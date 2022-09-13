// -------------------------------------------------------------------------
//    @FileName         :    NFDeclareProperty.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

//定义nocopy
#define DECLARE_UNCOPYABLE(Class) \
private: \
    Class(const Class&); \
    const Class& operator=(const Class&);

/** BOOL型属性接口 */
#define DECLARE_PROPERTY_BOOL_VARIANT(name, get_func, set_func) \
    protected: \
    bool m##name = false; \
    public: \
    virtual bool get_func() const { return m##name; } \
    virtual void set_func(const bool value) \
    {\
        m##name = value;\
    }

#define DECLARE_PROPERTY_BOOL_VARIANT_NULL(name, get_func, set_func) \
    public: \
    virtual bool get_func() const = 0; \
    virtual void set_func(const bool value) = 0;\

// 默认参数
#define DECLARE_PROPERTY_BOOL(name) DECLARE_PROPERTY_BOOL_VARIANT(name, Get##name, Set##name)

#define DECLARE_PROPERTY_BOOL_NULL(name) DECLARE_PROPERTY_BOOL_VARIANT_NULL(name, Get##name, Set##name)

/** INT型属性接口 */
#define DECLARE_PROPERTY_INT32_VARIANT(name, get_func, set_func) \
    protected: \
    int32_t m##name = 0; \
    public: \
    virtual int32_t get_func() const { return m##name; } \
    virtual void set_func(const int32_t value) \
    {\
        m##name = value;\
    }

#define DECLARE_PROPERTY_INT32_VARIANT_NULL(name, get_func, set_func) \
    public: \
    virtual int32_t get_func() const = 0; \
    virtual void set_func(const int32_t value) = 0;\

// 默认参数
#define DECLARE_PROPERTY_INT32(name) DECLARE_PROPERTY_INT32_VARIANT(name, Get##name, Set##name)

#define DECLARE_PROPERTY_INT32_NULL(name) DECLARE_PROPERTY_UINT32_VARIANT_NULL(name, Get##name, Set##name)

/** INT型属性接口 */
#define DECLARE_PROPERTY_UINT32_VARIANT(name, get_func, set_func) \
    protected: \
    uint32_t m##name = 0; \
    public: \
    virtual uint32_t get_func() const { return m##name; } \
    virtual void set_func(const uint32_t value) \
    {\
        m##name = value;\
    }

#define DECLARE_PROPERTY_UINT32_VARIANT_NULL(name, get_func, set_func) \
    public: \
    virtual uint32_t get_func() const = 0; \
    virtual void set_func(const uint32_t value) = 0;\

// 默认参数
#define DECLARE_PROPERTY_UINT32(name) DECLARE_PROPERTY_UINT32_VARIANT(name, Get##name, Set##name)

#define DECLARE_PROPERTY_UINT32_NULL(name) DECLARE_PROPERTY_UINT32_VARIANT_NULL(name, Get##name, Set##name)

///////////////////////////////////////////////////////////////////////////

/** INT64型属性接口 */
#define DECLARE_PROPERTY_INT64_VARIANT(name, get_func, set_func) \
    protected: \
    int64_t m##name = 0; \
    public: \
    virtual int64_t get_func() const { return m##name; } \
    virtual void set_func(const int64_t value) \
    {\
        m##name = value;\
    }

#define DECLARE_PROPERTY_INT64_VARIANT_NULL(name, get_func, set_func) \
    public: \
    virtual int64_t get_func() const = 0; \
    virtual void set_func(const int64_t value) = 0;\

// 默认参数
#define DECLARE_PROPERTY_INT64(name) DECLARE_PROPERTY_INT64_VARIANT(name, Get##name, Set##name)

#define DECLARE_PROPERTY_INT64_NULL(name) DECLARE_PROPERTY_INT64_VARIANT_NULL(name, Get##name, Set##name)
///////////////////////////////////////////////////////////////////////////

/** UINT64型属性接口 */
#define DECLARE_PROPERTY_UINT64_VARIANT(name, get_func, set_func) \
    protected: \
    uint64_t m##name = 0; \
    public: \
    virtual uint64_t get_func() const { return m##name; } \
    virtual void set_func(const uint64_t value) \
    {\
        m##name = value;\
    }

#define DECLARE_PROPERTY_UINT64_VARIANT_NULL(name, get_func, set_func) \
    public: \
    virtual uint64_t get_func() const = 0; \
    virtual void set_func(const uint64_t value) = 0;\

// 默认参数
#define DECLARE_PROPERTY_UINT64(name) DECLARE_PROPERTY_UINT64_VARIANT(name, Get##name, Set##name)

#define DECLARE_PROPERTY_UINT64_NULL(name) DECLARE_PROPERTY_UINT64_VARIANT_NULL(name, Get##name, Set##name)
///////////////////////////////////////////////////////////////////////////

/** float型属性接口 */
#define DECLARE_PROPERTY_FLOAT_VARIANT(name, get_func, set_func) \
    protected: \
    float m##name = 0; \
    public: \
    virtual float get_func() const { return m##name; } \
    virtual void set_func(const float value) \
    {\
        m##name = value;\
    }

#define DECLARE_PROPERTY_FLOAT_VARIANT_NULL(name, get_func, set_func) \
    public: \
    virtual float get_func() const = 0; \
    virtual void set_func(const float value) = 0; \

// 默认参数
#define DECLARE_PROPERTY_FLOAT(name) DECLARE_PROPERTY_FLOAT_VARIANT(name, Get##name, Set##name)

#define DECLARE_PROPERTY_FLOAT_NULL(name) DECLARE_PROPERTY_FLOAT_VARIANT_NULL(name, Get##name, Set##name)

///////////////////////////////////////////////////////////////////////////

/** double型属性接口 */
#define DECLARE_PROPERTY_DOUBLE_VARIANT(name, get_func, set_func) \
    protected: \
    double m##name = 0; \
    public: \
    virtual double get_func() const { return m##name; } \
    virtual void set_func(const double value) \
    {\
        m##name = value;\
    }

#define DECLARE_PROPERTY_DOUBLE_VARIANT_NULL(name, get_func, set_func) \
    public: \
    virtual double get_func() const = 0;\
    virtual void set_func(const double value) = 0; \

// 默认参数
#define DECLARE_PROPERTY_DOUBLE(name) DECLARE_PROPERTY_DOUBLE_VARIANT(name, Get##name, Set##name)

#define DECLARE_PROPERTY_DOUBLE_NULL(name) DECLARE_PROPERTY_DOUBLE_VARIANT_NULL(name, Get##name, Set##name)
///////////////////////////////////////////////////////////////////////////

/** string型属性接口 */
#define DECLARE_PROPERTY_STRING_VARIANT(name, get_func, set_func) \
    protected: \
    std::string m##name; \
    public: \
    virtual const std::string& get_func() const { return m##name; } \
    virtual void set_func(const std::string& value) \
    {\
        m##name = value;\
    }

#define DECLARE_PROPERTY_STRING_VARIANT_NULL(name, get_func, set_func) \
    public: \
    virtual const std::string& get_func() const = 0;\
    virtual void set_func(const std::string& value) = 0;\

// 默认参数
#define DECLARE_PROPERTY_STRING(name) DECLARE_PROPERTY_STRING_VARIANT(name, Get##name, Set##name)
#define DECLARE_PROPERTY_STRING_NULL(name) DECLARE_PROPERTY_STRING_VARIANT_NULL(name, Get##name, Set##name)
///////////////////////////////////////////////////////////////////////////

/** Object型属性接口 */
#define DECLARE_PROPERTY_OBJECT_VARIANT_PTR(object_type, name, get_func, set_func) \
    protected: \
    object_type* m##name = nullptr; \
    public: \
    virtual const object_type* get_func() const { return m##name; } \
    virtual object_type* get_func() { return m##name; } \
    virtual void set_func(object_type* value) \
    {\
        m##name = value;\
    }

#define DECLARE_PROPERTY_OBJECT_VARIANT_PTR_NULL(object_type, name, get_func, set_func) \
    public: \
    virtual const object_type* get_func() const = 0; \
    virtual object_type* get_func() = 0; \
    virtual void set_func(object_type* value) = 0; \

// 默认参数
#define DECLARE_PROPERTY_OBJECT_PTR(object_type, name) DECLARE_PROPERTY_OBJECT_VARIANT_PTR(object_type, name, Get##name, Set##name)

#define DECLARE_PROPERTY_OBJECT_PTR_NULL(object_type, name) DECLARE_PROPERTY_OBJECT_VARIANT_PTR_NULL(object_type, name, Get##name, Set##name)
///////////////////////////////////////////////////////////////////////////

/** Object型属性接口 */
#define DECLARE_PROPERTY_OBJECT_VARIANT(object_type, name, get_func, set_func) \
    protected: \
    object_type m##name; \
    public: \
    virtual const object_type& get_func() const { return m##name; } \
    virtual object_type& get_func() { return m##name; } \
    virtual void set_func(const object_type& value) \
    {\
        m##name = value;\
    }

#define DECLARE_PROPERTY_OBJECT_VARIANT_NULL(object_type, name, get_func, set_func) \
    public: \
    virtual const object_type& get_func() const = 0; \
    virtual object_type& get_func() = 0; \
    virtual void set_func(const object_type& value) = 0; \

// 默认参数
#define DECLARE_PROPERTY_OBJECT(object_type, name) DECLARE_PROPERTY_OBJECT_VARIANT(object_type, name, Get##name, Set##name)

#define DECLARE_PROPERTY_OBJECT_NULL(object_type, name) DECLARE_PROPERTY_OBJECT_VARIANT_NULL(object_type, name, Get##name, Set##name)
///////////////////////////////////////////////////////////////////////////


