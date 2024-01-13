#pragma once

#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <memory>
#include <initializer_list>
#include <type_traits>

#include "NFPlatform.h"

#ifdef _MSC_VER
#if _MSC_VER <= 1800 // VS 2013


#ifndef noexcept
#define noexcept throw()
#endif

#ifndef snprintf
#define snprintf _snprintf_s
#endif
#endif
#endif

enum JsonParse
{
	STANDARD,
	COMMENTS
};

class JsonValue;

class _NFExport NFJson final
{
public:
	// Types
	enum Type
	{
		NUL,
		NUMBER,
		BOOL,
		STRING,
		ARRAY,
		OBJECT
	};

	// Array and object typedefs
	typedef std::vector<NFJson> array;
	typedef std::map<std::string, NFJson> object;

	// Constructors for the various types of JSON value.
	NFJson() noexcept; // NUL
	NFJson(std::nullptr_t) noexcept; // NUL
	NFJson(double value); // NUMBER
	NFJson(int value); // NUMBER
	NFJson(bool value); // BOOL
	NFJson(const std::string& value); // STRING
	NFJson(std::string&& value); // STRING
	NFJson(const char* value); // STRING
	NFJson(const array& values); // ARRAY
	NFJson(array&& values); // ARRAY
	NFJson(const object& values); // OBJECT
	NFJson(object&& values); // OBJECT

	// Implicit constructor: anything with a to_json() function.
	template <class T, class = decltype(&T::to_json)>
	NFJson(const T& t) : NFJson(t.to_json())
	{
	}

	// This prevents Json(some_pointer) from accidentally producing a bool. Use
	// Json(bool(some_pointer)) if that behavior is desired.
	NFJson(void*) = delete;

	// Accessors
	Type type() const;

	bool is_null() const
	{
		return type() == NUL;
	}

	bool is_number() const
	{
		return type() == NUMBER;
	}

	bool is_bool() const
	{
		return type() == BOOL;
	}

	bool is_string() const
	{
		return type() == STRING;
	}

	bool is_array() const
	{
		return type() == ARRAY;
	}

	bool is_object() const
	{
		return type() == OBJECT;
	}

	// Return the enclosed value if this is a number, 0 otherwise. Note that json11 does not
	// distinguish between integer and non-integer numbers - number_value() and int_value()
	// can both be applied to a NUMBER-typed object.
	double number_value() const;
	int int_value() const;

	// Return the enclosed value if this is a boolean, false otherwise.
	bool bool_value() const;
	// Return the enclosed string if this is a string, "" otherwise.
	const std::string& string_value() const;
	// Return the enclosed std::vector if this is an array, or an empty vector otherwise.
	const array& array_items() const;
	// Return the enclosed std::map if this is an object, or an empty map otherwise.
	const object& object_items() const;

	// Return a reference to arr[i] if this is an array, Json() otherwise.
	const NFJson& operator[](size_t i) const;
	// Return a reference to obj[key] if this is an object, Json() otherwise.
	const NFJson& operator[](const std::string& key) const;

	// Serialize.
	void dump(std::string& out) const;

	std::string dump() const
	{
		std::string out;
		dump(out);
		return out;
	}

	// Parse. If parse fails, return Json() and assign an error message to err.
	static NFJson parse(const std::string& in,
	                    std::string& err,
	                    JsonParse strategy = JsonParse::STANDARD);

	static NFJson parse(const char* in,
	                    std::string& err,
	                    JsonParse strategy = JsonParse::STANDARD)
	{
		if (in)
		{
			return parse(std::string(in), err, strategy);
		}
		else
		{
			err = "null input";
			return nullptr;
		}
	}

	// Parse multiple objects, concatenated or separated by whitespace
	static std::vector<NFJson> parse_multi(
		const std::string& in,
		std::string::size_type& parser_stop_pos,
		std::string& err,
		JsonParse strategy = JsonParse::STANDARD);

	static inline std::vector<NFJson> parse_multi(
		const std::string& in,
		std::string& err,
		JsonParse strategy = JsonParse::STANDARD)
	{
		std::string::size_type parser_stop_pos;
		return parse_multi(in, parser_stop_pos, err, strategy);
	}

	bool operator==(const NFJson& rhs) const;
	bool operator<(const NFJson& rhs) const;

	bool operator!=(const NFJson& rhs) const
	{
		return !(*this == rhs);
	}

	bool operator<=(const NFJson& rhs) const
	{
		return !(rhs < *this);
	}

	bool operator>(const NFJson& rhs) const
	{
		return (rhs < *this);
	}

	bool operator>=(const NFJson& rhs) const
	{
		return !(*this < rhs);
	}

	/* has_shape(types, err)
	 *
	 * Return true if this is a JSON object and, for each item in types, has a field of
	 * the given type. If not, return false and set err to a descriptive message.
	 */
	typedef std::initializer_list<std::pair<std::string, Type>> shape;
	bool has_shape(const shape& types, std::string& err) const;

private:
	std::shared_ptr<JsonValue> m_ptr;
};

// Internal class hierarchy - JsonValue objects are not exposed to users of this API.
class JsonValue
{
protected:
	friend class NFJson;
	friend class JsonInt;
	friend class JsonDouble;
	virtual NFJson::Type type() const = 0;
	virtual bool equals(const JsonValue* other) const = 0;
	virtual bool less(const JsonValue* other) const = 0;
	virtual void dump(std::string& out) const = 0;
	virtual double number_value() const;
	virtual int int_value() const;
	virtual bool bool_value() const;
	virtual const std::string& string_value() const;
	virtual const NFJson::array& array_items() const;
	virtual const NFJson& operator[](size_t i) const;
	virtual const NFJson::object& object_items() const;
	virtual const NFJson& operator[](const std::string& key) const;

	virtual ~JsonValue()
	{
	}
};

