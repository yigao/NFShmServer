// -------------------------------------------------------------------------
//    @FileName         :    NFShmTree.h
//    @Author           :    gaoyi
//    @Date             :    23-7-24
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmTree
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFShmStl.h"
#include "NFShmList.h"
#include <iterator>
#include <algorithm>
#include <vector>
#include <type_traits>

typedef bool nfshm_Rb_tree_Color_type;
const nfshm_Rb_tree_Color_type _S_rb_tree_red = false;
const nfshm_Rb_tree_Color_type _S_rb_tree_black = true;

struct NFShmTreeNodeBase
{
    typedef nfshm_Rb_tree_Color_type _Color_type;
    typedef NFShmTreeNodeBase *_Base_ptr;

    NFShmTreeNodeBase()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        _M_color = _S_rb_tree_red;
        _M_parent = INVALID_ID;
        _M_left = INVALID_ID;
        _M_right = INVALID_ID;
        m_self = INVALID_ID;

        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    _Color_type _M_color;
    int _M_parent;
    int _M_left;
    int _M_right;
    int m_self;
};

template<class Value>
struct NFShmTreeNode : public NFShmTreeNodeBase
{
    typedef NFShmTreeNode<Value> *_Link_type;
    Value _M_value_field;

    NFShmTreeNode()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        if (std::numeric_limits<Value>::is_specialized)
        {
            std::_Construct(&_M_value_field);
        }
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

template<class Tp, int MAX_SIZE>
struct NFShmTreeBase
{
    NFShmTreeBase()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    ~NFShmTreeBase()
    {

    }

    int CreateInit()
    {
        _M_header = NULL;
        _M_header = _M_get_node();
        return 0;
    }

    int ResumeInit()
    {
        _M_header = NULL;
        _M_header = &m_listNode.back();
        return 0;
    }

protected:
    NFShmTreeNode<Tp> *_M_header;
    NFShmList<NFShmTreeNode<Tp>, MAX_SIZE + 1> m_listNode;

    NFShmTreeNode<Tp> *_M_get_node()
    {
        if (!m_listNode.full())
        {
            m_listNode.push_front();
            auto iter = m_listNode.begin();
            NF_ASSERT(iter != m_listNode.end());
            NFShmTreeNode<Tp> *pNode = &(*iter);
            pNode->m_self = iter.m_node->m_self;
            return pNode;
        }

        return NULL;
    }

    void _M_put_node(NFShmTreeNode<Tp> *pNode)
    {
        if (pNode)
        {
            auto iter = m_listNode.GetIterator(pNode->m_self);
            m_listNode.erase(iter);
        }
    }

    NFShmTreeNode<Tp>* get_node(int index)
    {
        return m_listNode.GetData(index);
    }

    int _S_minimum(NFShmTreeNodeBase *__x)
    {
        while (get_node(__x->_M_left) != NULL)
        {
            __x = get_node(__x->_M_left);
        }

        return __x->m_self;
    }

    int _S_maximum(NFShmTreeNodeBase *__x)
    {
        while (get_node(__x->_M_right) != NULL)
        {
            __x = get_node(__x->_M_right);
        }

        return __x->m_self;
    }


    void _Rb_tree_rotate_left(NFShmTreeNodeBase *__x, NFShmTreeNodeBase *&__root)
    {
        NFShmTreeNodeBase *__y = get_node(__x->_M_right);
        __x->_M_right = __y->_M_left;
        if (get_node(__y->_M_left) != 0)
        {
            get_node(__y->_M_left)->_M_parent = __x->m_self;
        }
        __y->_M_parent = __x->_M_parent;

        if (__x == __root)
        {
            __root = __y;
        }
        else if (__x->m_self == get_node(__x->_M_parent)->_M_left)
        {
            get_node(__x->_M_parent)->_M_left = __y->m_self;
        }
        else
        {
            get_node(__x->_M_parent)->_M_right = __y->m_self;
        }
        __y->_M_left = __x->m_self;
        __x->_M_parent = __y->m_self;
    }

    void _Rb_tree_rotate_right(NFShmTreeNodeBase *__x, NFShmTreeNodeBase *&__root)
    {
        NFShmTreeNodeBase *__y = get_node(__x->_M_left);
        __x->_M_left = __y->_M_right;
        if (get_node(__y->_M_right) != 0)
        {
            get_node(__y->_M_right)->_M_parent = __x->m_self;
        }
        __y->_M_parent = __x->_M_parent;

        if (__x == __root)
        {
            __root = __y;
        }
        else if (__x->m_self == get_node(__x->_M_parent)->_M_right)
        {
            get_node(__x->_M_parent)->_M_right = __y->m_self;
        }
        else
        {
            get_node(__x->_M_parent)->_M_left = __y->m_self;
        }
        __y->_M_right = __x->m_self;
        __x->_M_parent = __y->m_self;
    }

    void _Rb_tree_rebalance(NFShmTreeNodeBase *__x, NFShmTreeNodeBase *&__root)
    {
        __x->_M_color = _S_rb_tree_red;
        while (__x != __root && get_node(__x->_M_parent)->_M_color == _S_rb_tree_red)
        {
            if (__x->_M_parent == get_node(get_node(__x->_M_parent)->_M_parent)->_M_left)
            {
                NFShmTreeNodeBase *__y = get_node(get_node(__x->_M_parent)->_M_parent)->_M_right;
                if (__y && __y->_M_color == _S_rb_tree_red)
                {
                    get_node(__x->_M_parent)->_M_color = _S_rb_tree_black;
                    __y->_M_color = _S_rb_tree_black;
                    get_node(get_node(__x->_M_parent)->_M_parent)->_M_color = _S_rb_tree_red;
                    __x = get_node(get_node(__x->_M_parent)->_M_parent);
                }
                else
                {
                    if (__x == get_node(get_node(__x->_M_parent)->_M_right))
                    {
                        __x = get_node(__x->_M_parent);
                        _Rb_tree_rotate_left(__x, __root);
                    }
                    get_node(__x->_M_parent)->_M_color = _S_rb_tree_black;
                    get_node(get_node(__x->_M_parent)->_M_parent)->_M_color = _S_rb_tree_red;
                    _Rb_tree_rotate_right(get_node(get_node(__x->_M_parent)->_M_parent), __root);
                }
            }
            else
            {
                NFShmTreeNodeBase *__y = get_node(get_node(get_node(__x->_M_parent)->_M_parent)->_M_left);
                if (__y && __y->_M_color == _S_rb_tree_red)
                {
                    get_node(__x->_M_parent)->_M_color = _S_rb_tree_black;
                    __y->_M_color = _S_rb_tree_black;
                    get_node(get_node(__x->_M_parent)->_M_parent)->_M_color = _S_rb_tree_red;
                    __x = get_node(get_node(__x->_M_parent)->_M_parent);
                }
                else
                {
                    if (__x == get_node(get_node(__x->_M_parent)->_M_left))
                    {
                        __x = get_node(__x->_M_parent);
                        _Rb_tree_rotate_right(__x, __root);
                    }
                    get_node(__x->_M_parent)->_M_color = _S_rb_tree_black;
                    get_node(get_node(__x->_M_parent)->_M_parent)->_M_color = _S_rb_tree_red;
                    _Rb_tree_rotate_left(get_node(get_node(__x->_M_parent)->_M_parent), __root);
                }
            }
        }
        __root->_M_color = _S_rb_tree_black;
    }

    NFShmTreeNodeBase *_Rb_tree_rebalance_for_erase(NFShmTreeNodeBase *__z,
                                                    NFShmTreeNodeBase *&__root,
                                                    NFShmTreeNodeBase *&__leftmost,
                                                    NFShmTreeNodeBase *&__rightmost)
    {
        NFShmTreeNodeBase *__y = __z;
        NFShmTreeNodeBase *__x = 0;
        NFShmTreeNodeBase *__x_parent = 0;
        if (get_node(__y->_M_left) == 0)     // __z has at most one non-null child. y == z.
        {
            __x = get_node(__y->_M_right);     // __x might be null.
        }
        else
        {
            if (get_node(__y->_M_right) == 0)  // __z has exactly one non-null child. y == z.
            {
                __x = get_node(__y->_M_left);    // __x is not null.
            }
            else
            {                   // __z has two non-null children.  Set __y to
                __y = get_node(__y->_M_right);   //   __z's successor.  __x might be null.
                while (get_node(__y->_M_left) != 0)
                {
                    __y = get_node(__y->_M_left);
                }
                __x = get_node(__y->_M_right);
            }
        }

        if (__y != __z)
        {          // relink y in place of z.  y is z's successor
            get_node(__z->_M_left)->_M_parent = __y->m_self;
            __y->_M_left = __z->_M_left;
            if (__y != get_node(__z->_M_right))
            {
                __x_parent = get_node(__y->_M_parent);
                if (__x)
                {
                    __x->_M_parent = __y->_M_parent;
                }
                get_node(__y->_M_parent)->_M_left = __x->m_self;      // __y must be a child of _M_left
                __y->_M_right = __z->_M_right;
                get_node(__z->_M_right)->_M_parent = __y->m_self;
            }
            else
            {
                __x_parent = __y;
            }

            if (__root == __z)
            {
                __root = __y;
            }
            else if (get_node(get_node(__z->_M_parent)->_M_left) == __z)
            {
                get_node(__z->_M_parent)->_M_left = __y->m_self;
            }
            else
            {
                get_node(__z->_M_parent)->_M_right = __y->m_self;
            }
            __y->_M_parent = __z->_M_parent;
            std::swap(__y->_M_color, __z->_M_color);
            __y = __z;
            // __y now points to node to be actually deleted
        }
        else
        {                        // __y == __z
            __x_parent = get_node(__y->_M_parent);
            if (__x)
            {
                __x->_M_parent = __y->_M_parent;
            }

            if (__root == __z)
            {
                __root = __x;
            }
            else if (get_node(get_node(__z->_M_parent)->_M_left) == __z)
            {
                get_node(__z->_M_parent)->_M_left = __x->m_self;
            }
            else
            {
                get_node(__z->_M_parent)->_M_right = __x->m_self;
            }
            if (__leftmost == __z)
            {
                if (get_node(__z->_M_right) == 0)        // __z->_M_left must be null also
                {
                    __leftmost = get_node(__z->_M_parent);
                }
                    // makes __leftmost == _M_header if __z == __root
                else
                {
                    __leftmost = get_node(_S_minimum(__x));
                }
            }
            if (__rightmost == __z)
            {
                if (get_node(__z->_M_left) == 0)         // __z->_M_right must be null also
                {
                    __rightmost = get_node(__z->_M_parent);
                }
                    // makes __rightmost == _M_header if __z == __root
                else                      // __x == __z->_M_left
                {
                    __rightmost = get_node(_S_maximum(__x));
                }
            }
        }
        if (__y->_M_color != _S_rb_tree_red)
        {
            while (__x != __root && (__x == 0 || __x->_M_color == _S_rb_tree_black))
            {
                if (__x == get_node(__x_parent->_M_left))
                {
                    NFShmTreeNodeBase *__w = get_node(__x_parent->_M_right);
                    if (__w->_M_color == _S_rb_tree_red)
                    {
                        __w->_M_color = _S_rb_tree_black;
                        __x_parent->_M_color = _S_rb_tree_red;
                        _Rb_tree_rotate_left(__x_parent, __root);
                        __w = get_node(__x_parent->_M_right);
                    }
                    if ((__w->_M_left == 0 ||
                         get_node(__w->_M_left)->_M_color == _S_rb_tree_black) &&
                        (__w->_M_right == 0 ||
                         get_node(__w->_M_right)->_M_color == _S_rb_tree_black))
                    {
                        __w->_M_color = _S_rb_tree_red;
                        __x = __x_parent;
                        __x_parent = get_node(__x_parent->_M_parent);
                    }
                    else
                    {
                        if (__w->_M_right == 0 ||
                            get_node(__w->_M_right)->_M_color == _S_rb_tree_black)
                        {
                            if (get_node(__w->_M_left)) get_node(__w->_M_left)->_M_color = _S_rb_tree_black;
                            __w->_M_color = _S_rb_tree_red;
                            _Rb_tree_rotate_right(__w, __root);
                            __w = get_node(__x_parent->_M_right);
                        }
                        __w->_M_color = __x_parent->_M_color;
                        __x_parent->_M_color = _S_rb_tree_black;
                        if (get_node(__w->_M_right)) get_node(__w->_M_right)->_M_color = _S_rb_tree_black;
                        _Rb_tree_rotate_left(__x_parent, __root);
                        break;
                    }
                }
                else
                {                  // same as above, with _M_right <-> _M_left.
                    NFShmTreeNodeBase *__w = get_node(__x_parent->_M_left);
                    if (__w->_M_color == _S_rb_tree_red)
                    {
                        __w->_M_color = _S_rb_tree_black;
                        __x_parent->_M_color = _S_rb_tree_red;
                        _Rb_tree_rotate_right(__x_parent, __root);
                        __w = get_node(__x_parent->_M_left);
                    }
                    if ((get_node(__w->_M_right) == 0 ||
                         get_node(__w->_M_right)->_M_color == _S_rb_tree_black) &&
                        (get_node(__w->_M_left) == 0 ||
                         get_node(__w->_M_left)->_M_color == _S_rb_tree_black))
                    {
                        __w->_M_color = _S_rb_tree_red;
                        __x = __x_parent;
                        __x_parent = get_node(__x_parent->_M_parent);
                    }
                    else
                    {
                        if (get_node(__w->_M_left) == 0 ||
                            get_node(__w->_M_left)->_M_color == _S_rb_tree_black)
                        {
                            if (get_node(__w->_M_right)) get_node(__w->_M_right)->_M_color = _S_rb_tree_black;
                            __w->_M_color = _S_rb_tree_red;
                            _Rb_tree_rotate_left(__w, __root);
                            __w = get_node(__x_parent->_M_left);
                        }
                        __w->_M_color = __x_parent->_M_color;
                        __x_parent->_M_color = _S_rb_tree_black;
                        if (get_node(__w->_M_left)) get_node(__w->_M_left)->_M_color = _S_rb_tree_black;
                        _Rb_tree_rotate_right(__x_parent, __root);
                        break;
                    }
                }
            }
            if (__x) __x->_M_color = _S_rb_tree_black;
        }
        return __y;
    }
};

template<class Container>
struct NFShmRbTreeBaseIterator
{
    typedef NFShmTreeNodeBase::_Base_ptr _Base_ptr;
    typedef bidirectional_iterator_tag iterator_category;
    typedef ptrdiff_t difference_type;
    _Base_ptr _M_node;
    Container *m_pContainer;

    NFShmRbTreeBaseIterator() : m_pContainer(NULL), _M_node(NULL)
    {

    }

    void _M_increment()
    {
        if (m_pContainer->get_node(_M_node->_M_right) != NULL)
        {
            _M_node = m_pContainer->get_node(_M_node->_M_right);
            while (m_pContainer->get_node(_M_node->_M_left) != NULL)
                _M_node = m_pContainer->get_node(_M_node->_M_left);
        }
        else
        {
            _Base_ptr __y = m_pContainer->get_node(_M_node->_M_parent);
            while (_M_node == m_pContainer->get_node(__y->_M_right))
            {
                _M_node = __y;
                __y = m_pContainer->get_node(__y->_M_parent);
            }
            if (m_pContainer->get_node(_M_node->_M_right) != __y)
                _M_node = __y;
        }
    }

    void _M_decrement()
    {
        if (_M_node->_M_color == _S_rb_tree_red &&
            m_pContainer->get_node(m_pContainer->get_node(_M_node->_M_parent)->_M_parent) == _M_node)
            _M_node = m_pContainer->get_node(_M_node->_M_right);
        else if (m_pContainer->get_node(_M_node->_M_left) != 0)
        {
            _Base_ptr __y = m_pContainer->get_node(_M_node->_M_left);
            while (m_pContainer->get_node(__y->_M_right) != 0)
                __y = m_pContainer->get_node(__y->_M_right);
            _M_node = __y;
        }
        else
        {
            _Base_ptr __y = m_pContainer->get_node(_M_node->_M_parent);
            while (_M_node == m_pContainer->get_node(__y->_M_left))
            {
                _M_node = __y;
                __y = m_pContainer->get_node(__y->_M_parent);
            }
            _M_node = __y;
        }
    }
};

template<class Container, class Value, class Ref, class Ptr>
struct NFShmRbTreeIterator : public NFShmRbTreeBaseIterator<Container>
{
    typedef Value value_type;
    typedef Ref reference;
    typedef Ptr pointer;
    typedef NFShmRbTreeIterator<Container, Value, Value &, Value *>
            iterator;
    typedef NFShmRbTreeIterator<Container, Value, const Value &, const Value *>
            const_iterator;
    typedef NFShmRbTreeIterator<Container, Value, Ref, Ptr>
            _Self;
    typedef NFShmTreeNode<Value> *_Link_type;

    using NFShmRbTreeBaseIterator<Container>::m_pContainer;
    using NFShmRbTreeBaseIterator<Container>::_M_node;
    using NFShmRbTreeBaseIterator<Container>::_M_increment;
    using NFShmRbTreeBaseIterator<Container>::_M_decrement;

    NFShmRbTreeIterator() {}

    NFShmRbTreeIterator(Container pContainer, _Link_type __x)
    {
        m_pContainer = pContainer;
        _M_node = __x;
    }

    NFShmRbTreeIterator(Container pContainer, const iterator &__it)
    {
        m_pContainer = pContainer;
        _M_node = __it._M_node;
    }

    reference operator*() const { return _Link_type(_M_node)->_M_value_field; }

    pointer operator->() const { return &(operator*()); }

    _Self &operator++()
    {
        _M_increment();
        return *this;
    }

    _Self operator++(int)
    {
        _Self __tmp = *this;
        _M_increment();
        return __tmp;
    }

    _Self &operator--()
    {
        _M_decrement();
        return *this;
    }

    _Self operator--(int)
    {
        _Self __tmp = *this;
        _M_decrement();
        return __tmp;
    }
};

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
class NFShmTree : protected NFShmTreeBase<Value, MAX_SIZE>
{
    typedef NFShmTreeBase<Value, MAX_SIZE> _Base;
protected:
    typedef NFShmTreeNode<Value> Rb_tree_node;
    typedef nfshm_Rb_tree_Color_type Color_type;
    typedef NFShmTreeNodeBase *_Base_ptr;
public:
    typedef Key key_type;
    typedef Value value_type;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef Rb_tree_node *_Link_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

protected:
    using _Base::_M_get_node;
    using _Base::_M_put_node;
    using _Base::_M_header;
    using _Base::m_listNode;
    using _Base::get_node;
    using _Base::_S_minimum;
    using _Base::_S_maximum;
    using _Base::_Rb_tree_rotate_left;
    using _Base::_Rb_tree_rotate_right;
    using _Base::_Rb_tree_rebalance;
    using _Base::_Rb_tree_rebalance_for_erase;

protected:

    _Link_type _M_create_node(const value_type &__x)
    {
        _Link_type __tmp = _M_get_node();
        if (__tmp)
        {
            __tmp->_M_value_field = __x;
        }
        return __tmp;
    }

    _Link_type _M_clone_node(_Link_type __x)
    {
        _Link_type __tmp = _M_create_node(__x->_M_value_field);
        __tmp->_M_color = __x->_M_color;
        __tmp->_M_left = INVALID_ID;
        __tmp->_M_right = INVALID_ID;
        return __tmp;
    }

    void destroy_node(_Link_type __p)
    {
        _M_put_node(__p);
    }


protected:
    size_type _M_node_count; // keeps track of size of tree
    Compare _M_key_compare;

    int &_M_root() const { return (int &) _M_header->_M_parent; }

    int &_M_leftmost() const { return (int &) _M_header->_M_left; }

    int &_M_rightmost() const { return (int &) _M_header->_M_right; }

    static int &_S_left(_Link_type __x) { return (int &) (__x->_M_left); }

    static int &_S_right(_Link_type __x) { return (int &) (__x->_M_right); }

    static int &_S_parent(_Link_type __x) { return (int &) (__x->_M_parent); }

    static reference _S_value(_Link_type __x) { return __x->_M_value_field; }

    static const Key &_S_key(_Link_type __x) { return KeyOfValue()(_S_value(__x)); }

    static Color_type &_S_color(_Link_type __x) { return (Color_type &) (__x->_M_color); }

    static int &_S_left(_Base_ptr __x) { return (int &) (__x->_M_left); }

    static int &_S_right(_Base_ptr __x) { return (int &) (__x->_M_right); }

    static int &_S_parent(_Base_ptr __x) { return (int &) (__x->_M_parent); }

    static reference _S_value(_Base_ptr __x) { return ((_Link_type) __x)->_M_value_field; }

    static const Key &_S_key(_Base_ptr __x) { return KeyOfValue()(_S_value(_Link_type(__x))); }

    static Color_type &_S_color(_Base_ptr __x) { return (Color_type &) (_Link_type(__x)->_M_color); }


public:
    typedef NFShmRbTreeIterator<_Base, value_type, reference, pointer> iterator;
    typedef NFShmRbTreeIterator<_Base, value_type, const_reference, const_pointer>
            const_iterator;

    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;

private:
    iterator _M_insert(_Base_ptr __x, _Base_ptr __y, const value_type &__v);

    _Link_type _M_copy(_Link_type __x, _Link_type __p);

    void _M_erase(_Link_type __x);

public:
    // allocation/deallocation
    NFShmTree() : _Base(), _M_node_count(0), _M_key_compare()
    {
        _M_empty_initialize();
    }

    NFShmTree(const Compare &__comp) : _Base(), _M_node_count(0), _M_key_compare(__comp)
    {
        _M_empty_initialize();
    }

    ~NFShmTree()
    {
        clear();
    }

private:
    void _M_empty_initialize()
    {
        _S_color(_M_header) = _S_rb_tree_red; // used to distinguish header from
        // __root, in iterator.operator++
        _M_root() = INVALID_ID;
        _M_leftmost() = _M_header->m_self;
        _M_rightmost() = _M_header->m_self;
    }

public:
    // accessors:
    Compare key_comp() const { return _M_key_compare; }

    iterator begin() { return iterator(this, get_node(_M_leftmost())); }

    const_iterator begin() const { return const_iterator(this, get_node(_M_leftmost())); }

    iterator end() { return iterator(this, _M_header); }

    const_iterator end() const { return const_iterator(this, _M_header); }

    reverse_iterator rbegin() { return reverse_iterator(end()); }

    const_reverse_iterator rbegin() const
    {
        return const_reverse_iterator(end());
    }

    reverse_iterator rend() { return reverse_iterator(begin()); }

    const_reverse_iterator rend() const
    {
        return const_reverse_iterator(begin());
    }

    bool empty() const { return _M_node_count == 0; }

    size_type size() const { return _M_node_count; }

    size_type max_size() const { return MAX_SIZE; }

public:
    // insert/erase
    pair<iterator, bool> insert_unique(const value_type &__x);

    iterator insert_equal(const value_type &__x);

    iterator insert_unique(iterator __position, const value_type &__x);

    iterator insert_equal(iterator __position, const value_type &__x);

    template<class _InputIterator>
    void insert_unique(_InputIterator __first, _InputIterator __last);

    template<class _InputIterator>
    void insert_equal(_InputIterator __first, _InputIterator __last);

    void insert_unique(const_iterator __first, const_iterator __last);

    void insert_unique(const value_type *__first, const value_type *__last);

    void insert_equal(const_iterator __first, const_iterator __last);

    void insert_equal(const value_type *__first, const value_type *__last);

    void erase(iterator __position);

    size_type erase(const key_type &__x);

    void erase(iterator __first, iterator __last);

    void erase(const key_type *__first, const key_type *__last);

    void clear()
    {
        if (_M_node_count != 0)
        {
            _M_erase(get_node(_M_root()));
            _M_leftmost() = _M_header->m_self;
            _M_root() = INVALID_ID;
            _M_rightmost() = _M_header->m_self;
            _M_node_count = 0;
        }
    }

public:
    // set operations:
    iterator find(const key_type &__x);

    const_iterator find(const key_type &__x) const;

    size_type count(const key_type &__x) const;

    iterator lower_bound(const key_type &__x);

    const_iterator lower_bound(const key_type &__x) const;

    iterator upper_bound(const key_type &__x);

    const_iterator upper_bound(const key_type &__x) const;

    pair<iterator, iterator> equal_range(const key_type &__x);

    pair<const_iterator, const_iterator> equal_range(const key_type &__x) const;

public:
    // Debugging.
    bool __rb_verify() const;
};

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::iterator
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::_M_insert(_Base_ptr __x_, _Base_ptr __y_, const Value &__v)
{
    _Link_type __x = (_Link_type) __x_;
    _Link_type __y = (_Link_type) __y_;
    _Link_type __z;

    if (__y == _M_header || __x != 0 ||
        _M_key_compare(KeyOfValue()(__v), _S_key(__y)))
    {
        __z = _M_create_node(__v);
        _S_left(__y) = __z->m_self;               // also makes _M_leftmost() = __z
        //    when __y == _M_header
        if (__y == _M_header)
        {
            _M_root() = __z->m_self;
            _M_rightmost() = __z->m_self;
        }
        else if (__y->m_self == _M_leftmost())
            _M_leftmost() = __z->m_self;   // maintain _M_leftmost() pointing to min node
    }
    else
    {
        __z = _M_create_node(__v);
        _S_right(__y) = __z->m_self;
        if (__y->m_self == _M_rightmost())
            _M_rightmost() = __z->m_self;  // maintain _M_rightmost() pointing to max node
    }
    _S_parent(__z) = __y->m_self;
    _S_left(__z) = INVALID_ID;
    _S_right(__z) = INVALID_ID;
    _Rb_tree_rebalance(__z, get_node(_M_header->_M_parent));
    ++_M_node_count;
    return iterator(__z);
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::iterator
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::insert_equal(const Value &__v)
{
    _Link_type __y = _M_header;
    _Link_type __x = get_node(_M_root());
    while (__x != 0)
    {
        __y = __x;
        __x = _M_key_compare(KeyOfValue()(__v), _S_key(__x)) ?
              get_node(_S_left(__x)) : get_node(_S_right(__x));
    }
    return _M_insert(__x, __y, __v);
}


template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
pair<typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::iterator, bool>
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::insert_unique(const Value &__v)
{
    _Link_type __y = _M_header;
    _Link_type __x = get_node(_M_root());
    bool __comp = true;
    while (__x != NULL)
    {
        __y = __x;
        __comp = _M_key_compare(KeyOfValue()(__v), _S_key(__x));
        __x = __comp ? get_node(_S_left(__x)) : get_node(_S_right(__x));
    }
    iterator __j = iterator(this, __y);
    if (__comp)
    {
        if (__j == begin())
        {
            return pair<iterator, bool>(_M_insert(__x, __y, __v), true);
        }
        else
        {
            --__j;
        }
    }
    if (_M_key_compare(_S_key(__j._M_node), KeyOfValue()(__v)))
    {
        return pair<iterator, bool>(_M_insert(__x, __y, __v), true);
    }
    return pair<iterator, bool>(__j, false);
}


template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::iterator
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::insert_unique(iterator __position, const Value &__v)
{
    if (__position._M_node == get_node(_M_header->_M_left))
    { // begin()
        if (size() > 0 &&
            _M_key_compare(KeyOfValue()(__v), _S_key(__position._M_node)))
            return _M_insert(__position._M_node, __position._M_node, __v);
            // first argument just needs to be non-null
        else
            return insert_unique(__v).first;
    }
    else if (__position._M_node == _M_header)
    { // end()
        if (_M_key_compare(_S_key(_M_rightmost()), KeyOfValue()(__v)))
            return _M_insert(0, _M_rightmost(), __v);
        else
            return insert_unique(__v).first;
    }
    else
    {
        iterator __before = __position;
        --__before;
        if (_M_key_compare(_S_key(__before._M_node), KeyOfValue()(__v))
            && _M_key_compare(KeyOfValue()(__v), _S_key(__position._M_node)))
        {
            if (_S_right(__before._M_node) == 0)
                return _M_insert(0, __before._M_node, __v);
            else
                return _M_insert(__position._M_node, __position._M_node, __v);
            // first argument just needs to be non-null
        }
        else
            return insert_unique(__v).first;
    }
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::iterator
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::insert_equal(iterator __position, const Value &__v)
{
    if (__position._M_node == _M_header->_M_left)
    { // begin()
        if (size() > 0 &&
            !_M_key_compare(_S_key(__position._M_node), KeyOfValue()(__v)))
            return _M_insert(__position._M_node, __position._M_node, __v);
            // first argument just needs to be non-null
        else
            return insert_equal(__v);
    }
    else if (__position._M_node == _M_header)
    {// end()
        if (!_M_key_compare(KeyOfValue()(__v), _S_key(_M_rightmost())))
            return _M_insert(0, _M_rightmost(), __v);
        else
            return insert_equal(__v);
    }
    else
    {
        iterator __before = __position;
        --__before;
        if (!_M_key_compare(KeyOfValue()(__v), _S_key(__before._M_node))
            && !_M_key_compare(_S_key(__position._M_node), KeyOfValue()(__v)))
        {
            if (_S_right(__before._M_node) == 0)
                return _M_insert(0, __before._M_node, __v);
            else
                return _M_insert(__position._M_node, __position._M_node, __v);
            // first argument just needs to be non-null
        }
        else
            return insert_equal(__v);
    }
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
template<class _II>
void NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::insert_equal(_II __first, _II __last)
{
    for (; __first != __last; ++__first)
        insert_equal(*__first);
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
template<class _II>
void NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::insert_unique(_II __first, _II __last)
{
    for (; __first != __last; ++__first)
        insert_unique(*__first);
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
void
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::insert_equal(const Value *__first, const Value *__last)
{
    for (; __first != __last; ++__first)
        insert_equal(*__first);
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
void
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::insert_equal(const_iterator __first, const_iterator __last)
{
    for (; __first != __last; ++__first)
        insert_equal(*__first);
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
void
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::insert_unique(const Value *__first, const Value *__last)
{
    for (; __first != __last; ++__first)
        insert_unique(*__first);
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
void NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::insert_unique(const_iterator __first, const_iterator __last)
{
    for (; __first != __last; ++__first)
        insert_unique(*__first);
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
inline void NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::erase(iterator __position)
{
    _Link_type __y =
            (_Link_type) _Rb_tree_rebalance_for_erase(__position._M_node,
                                                      _M_header->_M_parent,
                                                      _M_header->_M_left,
                                                      _M_header->_M_right);
    destroy_node(__y);
    --_M_node_count;
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::size_type
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::erase(const Key &__x)
{
    pair<iterator, iterator> __p = equal_range(__x);
    size_type __n = 0;
    distance(__p.first, __p.second, __n);
    erase(__p.first, __p.second);
    return __n;
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::_Link_type
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::_M_copy(_Link_type __x, _Link_type __p)
{
    // structural copy.  __x and __p must be non-null.
    _Link_type __top = _M_clone_node(__x);
    __top->_M_parent = __p;

    {
        if (__x->_M_right)
            __top->_M_right = _M_copy(_S_right(__x), __top);
        __p = __top;
        __x = _S_left(__x);

        while (__x != 0)
        {
            _Link_type __y = _M_clone_node(__x);
            __p->_M_left = __y;
            __y->_M_parent = __p;
            if (__x->_M_right)
                __y->_M_right = _M_copy(_S_right(__x), __y);
            __p = __y;
            __x = _S_left(__x);
        }
    }

    return __top;
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
void NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::_M_erase(_Link_type __x)
{
    // erase without rebalancing
    while (__x != NULL)
    {
        _M_erase(get_node(_S_right(__x)));
        _Link_type __y = get_node(_S_left(__x));
        destroy_node(__x);
        __x = __y;
    }
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
void NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::erase(iterator __first, iterator __last)
{
    if (__first == begin() && __last == end())
        clear();
    else
        while (__first != __last) erase(__first++);
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
void NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::erase(const Key *__first, const Key *__last)
{
    while (__first != __last) erase(*__first++);
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::iterator
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::find(const Key &__k)
{
    _Link_type __y = _M_header;      // Last node which is not less than __k.
    _Link_type __x = _M_root();      // Current node.

    while (__x != 0)
        if (!_M_key_compare(_S_key(__x), __k))
            __y = __x, __x = _S_left(__x);
        else
            __x = _S_right(__x);

    iterator __j = iterator(__y);
    return (__j == end() || _M_key_compare(__k, _S_key(__j._M_node))) ?
           end() : __j;
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::const_iterator
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::find(const Key &__k) const
{
    _Link_type __y = _M_header; /* Last node which is not less than __k. */
    _Link_type __x = get_node(_M_root()); /* Current node. */

    while (__x != 0)
    {
        if (!_M_key_compare(_S_key(__x), __k))
            __y = __x, __x = _S_left(__x);
        else
            __x = _S_right(__x);
    }
    const_iterator __j = const_iterator(__y);
    return (__j == end() || _M_key_compare(__k, _S_key(__j._M_node))) ?
           end() : __j;
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::size_type
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::count(const Key &__k) const
{
    pair<const_iterator, const_iterator> __p = equal_range(__k);
    size_type __n = 0;
    distance(__p.first, __p.second, __n);
    return __n;
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::iterator
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::lower_bound(const Key &__k)
{
    _Link_type __y = _M_header; /* Last node which is not less than __k. */
    _Link_type __x = get_node(_M_root()); /* Current node. */

    while (__x != 0)
        if (!_M_key_compare(_S_key(__x), __k))
            __y = __x, __x = _S_left(__x);
        else
            __x = _S_right(__x);

    return iterator(__y);
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::const_iterator
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::lower_bound(const Key &__k) const
{
    _Link_type __y = _M_header; /* Last node which is not less than __k. */
    _Link_type __x = get_node(_M_root()); /* Current node. */

    while (__x != 0)
        if (!_M_key_compare(_S_key(__x), __k))
            __y = __x, __x = _S_left(__x);
        else
            __x = _S_right(__x);

    return const_iterator(__y);
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::iterator
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::upper_bound(const Key &__k)
{
    _Link_type __y = _M_header; /* Last node which is greater than __k. */
    _Link_type __x = get_node(_M_root()); /* Current node. */

    while (__x != 0)
        if (_M_key_compare(__k, _S_key(__x)))
            __y = __x, __x = _S_left(__x);
        else
            __x = _S_right(__x);

    return iterator(__y);
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::const_iterator
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::upper_bound(const Key &__k) const
{
    _Link_type __y = _M_header; /* Last node which is greater than __k. */
    _Link_type __x = get_node(_M_root()); /* Current node. */

    while (__x != 0)
        if (_M_key_compare(__k, _S_key(__x)))
            __y = __x, __x = _S_left(__x);
        else
            __x = _S_right(__x);

    return const_iterator(__y);
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
inline
pair<typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::iterator,
        typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::iterator>
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::equal_range(const Key &__k)
{
    return pair<iterator, iterator>(lower_bound(__k), upper_bound(__k));
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
inline
pair<typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::const_iterator,
        typename NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::const_iterator>
NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>
::equal_range(const Key &__k) const
{
    return pair<const_iterator, const_iterator>(lower_bound(__k),
                                                upper_bound(__k));
}

inline int
__black_count(_Rb_tree_node_base *__node, _Rb_tree_node_base *__root)
{
    if (__node == 0)
        return 0;
    else
    {
        int __bc = __node->_M_color == _S_rb_tree_black ? 1 : 0;
        if (__node == __root)
            return __bc;
        else
            return __bc + __black_count(__node->_M_parent, __root);
    }
}

template<int MAX_SIZE, class Key, class Value, class KeyOfValue, class Compare>
bool NFShmTree<MAX_SIZE, Key, Value, KeyOfValue, Compare>::__rb_verify() const
{
    if (_M_node_count == 0 || begin() == end())
        return _M_node_count == 0 && begin() == end() &&
               get_node(_M_header->_M_left) == _M_header && get_node(_M_header->_M_right) == _M_header;

    int __len = __black_count(_M_leftmost(), _M_root());
    for (const_iterator __it = begin(); __it != end(); ++__it)
    {
        _Link_type __x = (_Link_type) __it._M_node;
        _Link_type __L = _S_left(__x);
        _Link_type __R = _S_right(__x);

        if (__x->_M_color == _S_rb_tree_red)
            if ((__L && __L->_M_color == _S_rb_tree_red) ||
                (__R && __R->_M_color == _S_rb_tree_red))
                return false;

        if (__L && _M_key_compare(_S_key(__x), _S_key(__L)))
            return false;
        if (__R && _M_key_compare(_S_key(__R), _S_key(__x)))
            return false;

        if (!__L && !__R && __black_count(__x, _M_root()) != __len)
            return false;
    }

    if (_M_leftmost() != _Rb_tree_node_base::_S_minimum(_M_root()))
        return false;
    if (_M_rightmost() != _Rb_tree_node_base::_S_maximum(_M_root()))
        return false;

    return true;
}
