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
        _M_header = &m_listNode().front();
        return 0;
    }

protected:
    NFShmTreeNode<Tp> *_M_header;
    NFShmList<Tp, MAX_SIZE + 1> m_listNode;

    NFShmTreeNode<Tp> *_M_get_node()
    {
        if (!m_listNode.full())
        {
            m_listNode.push_back();
            auto iter = m_listNode.rbegin();
            NF_ASSERT(iter != m_listNode.rend());
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

    NFShmTreeNode<Tp> get_node(int index)
    {
        auto pListNode = m_listNode.GetNode(index);
        if (pListNode)
        {
            NF_ASSERT(pListNode->m_valid);
            return &pListNode->m_data;
        }

        return NULL;
    }


    void _Rb_tree_rotate_left(NFShmTreeNodeBase* __x, NFShmTreeNodeBase*& __root)
    {
        NFShmTreeNodeBase* __y = get_node(__x->_M_right);
        __x->_M_right = __y->_M_left;
        if (__y->_M_left != INVALID_ID)
            get_node(__y->_M_left)->_M_parent = __x->m_self;
        __y->_M_parent = __x->_M_parent;

        if (__x == __root)
            __root = __y;
        else if (__x->m_self == get_node(__x->_M_parent)->_M_left)
            get_node(__x->_M_parent)->_M_left = __y->m_self;
        else
            get_node(__x->_M_parent)->_M_right = __y->m_self;
        __y->_M_left = __x->m_self;
        __x->_M_parent = __y->m_self;
    }

    void _Rb_tree_rotate_right(NFShmTreeNodeBase* __x, NFShmTreeNodeBase*& __root)
    {
        NFShmTreeNodeBase* __y = get_node(__x->_M_left);
        __x->_M_left = __y->_M_right;
        if (__y->_M_right != INVALID_ID)
            get_node(__y->_M_right)->_M_parent = __x;
        __y->_M_parent = __x->_M_parent;

        if (__x == __root)
            __root = __y;
        else if (__x->m_self == get_node(__x->_M_parent)->_M_right)
            get_node(__x->_M_parent)->_M_right = __y->m_self;
        else
            get_node(__x->_M_parent)->_M_left = __y->m_self;
        __y->_M_right = __x->m_self;
        __x->_M_parent = __y->m_self;
    }

    inline void
    _Rb_tree_rebalance(_Rb_tree_node_base* __x, _Rb_tree_node_base*& __root)
    {
        __x->_M_color = _S_rb_tree_red;
        while (__x != __root && __x->_M_parent->_M_color == _S_rb_tree_red) {
            if (__x->_M_parent == __x->_M_parent->_M_parent->_M_left) {
                _Rb_tree_node_base* __y = __x->_M_parent->_M_parent->_M_right;
                if (__y && __y->_M_color == _S_rb_tree_red) {
                    __x->_M_parent->_M_color = _S_rb_tree_black;
                    __y->_M_color = _S_rb_tree_black;
                    __x->_M_parent->_M_parent->_M_color = _S_rb_tree_red;
                    __x = __x->_M_parent->_M_parent;
                }
                else {
                    if (__x == __x->_M_parent->_M_right) {
                        __x = __x->_M_parent;
                        _Rb_tree_rotate_left(__x, __root);
                    }
                    __x->_M_parent->_M_color = _S_rb_tree_black;
                    __x->_M_parent->_M_parent->_M_color = _S_rb_tree_red;
                    _Rb_tree_rotate_right(__x->_M_parent->_M_parent, __root);
                }
            }
            else {
                _Rb_tree_node_base* __y = __x->_M_parent->_M_parent->_M_left;
                if (__y && __y->_M_color == _S_rb_tree_red) {
                    __x->_M_parent->_M_color = _S_rb_tree_black;
                    __y->_M_color = _S_rb_tree_black;
                    __x->_M_parent->_M_parent->_M_color = _S_rb_tree_red;
                    __x = __x->_M_parent->_M_parent;
                }
                else {
                    if (__x == __x->_M_parent->_M_left) {
                        __x = __x->_M_parent;
                        _Rb_tree_rotate_right(__x, __root);
                    }
                    __x->_M_parent->_M_color = _S_rb_tree_black;
                    __x->_M_parent->_M_parent->_M_color = _S_rb_tree_red;
                    _Rb_tree_rotate_left(__x->_M_parent->_M_parent, __root);
                }
            }
        }
        __root->_M_color = _S_rb_tree_black;
    }

    inline _Rb_tree_node_base*
    _Rb_tree_rebalance_for_erase(_Rb_tree_node_base* __z,
                                 _Rb_tree_node_base*& __root,
                                 _Rb_tree_node_base*& __leftmost,
                                 _Rb_tree_node_base*& __rightmost)
    {
        _Rb_tree_node_base* __y = __z;
        _Rb_tree_node_base* __x = 0;
        _Rb_tree_node_base* __x_parent = 0;
        if (__y->_M_left == 0)     // __z has at most one non-null child. y == z.
            __x = __y->_M_right;     // __x might be null.
        else
        if (__y->_M_right == 0)  // __z has exactly one non-null child. y == z.
            __x = __y->_M_left;    // __x is not null.
        else {                   // __z has two non-null children.  Set __y to
            __y = __y->_M_right;   //   __z's successor.  __x might be null.
            while (__y->_M_left != 0)
                __y = __y->_M_left;
            __x = __y->_M_right;
        }
        if (__y != __z) {          // relink y in place of z.  y is z's successor
            __z->_M_left->_M_parent = __y;
            __y->_M_left = __z->_M_left;
            if (__y != __z->_M_right) {
                __x_parent = __y->_M_parent;
                if (__x) __x->_M_parent = __y->_M_parent;
                __y->_M_parent->_M_left = __x;      // __y must be a child of _M_left
                __y->_M_right = __z->_M_right;
                __z->_M_right->_M_parent = __y;
            }
            else
                __x_parent = __y;
            if (__root == __z)
                __root = __y;
            else if (__z->_M_parent->_M_left == __z)
                __z->_M_parent->_M_left = __y;
            else
                __z->_M_parent->_M_right = __y;
            __y->_M_parent = __z->_M_parent;
            __STD::swap(__y->_M_color, __z->_M_color);
            __y = __z;
            // __y now points to node to be actually deleted
        }
        else {                        // __y == __z
            __x_parent = __y->_M_parent;
            if (__x) __x->_M_parent = __y->_M_parent;
            if (__root == __z)
                __root = __x;
            else
            if (__z->_M_parent->_M_left == __z)
                __z->_M_parent->_M_left = __x;
            else
                __z->_M_parent->_M_right = __x;
            if (__leftmost == __z)
                if (__z->_M_right == 0)        // __z->_M_left must be null also
                    __leftmost = __z->_M_parent;
                    // makes __leftmost == _M_header if __z == __root
                else
                    __leftmost = _Rb_tree_node_base::_S_minimum(__x);
            if (__rightmost == __z)
                if (__z->_M_left == 0)         // __z->_M_right must be null also
                    __rightmost = __z->_M_parent;
                    // makes __rightmost == _M_header if __z == __root
                else                      // __x == __z->_M_left
                    __rightmost = _Rb_tree_node_base::_S_maximum(__x);
        }
        if (__y->_M_color != _S_rb_tree_red) {
            while (__x != __root && (__x == 0 || __x->_M_color == _S_rb_tree_black))
                if (__x == __x_parent->_M_left) {
                    _Rb_tree_node_base* __w = __x_parent->_M_right;
                    if (__w->_M_color == _S_rb_tree_red) {
                        __w->_M_color = _S_rb_tree_black;
                        __x_parent->_M_color = _S_rb_tree_red;
                        _Rb_tree_rotate_left(__x_parent, __root);
                        __w = __x_parent->_M_right;
                    }
                    if ((__w->_M_left == 0 ||
                         __w->_M_left->_M_color == _S_rb_tree_black) &&
                        (__w->_M_right == 0 ||
                         __w->_M_right->_M_color == _S_rb_tree_black)) {
                        __w->_M_color = _S_rb_tree_red;
                        __x = __x_parent;
                        __x_parent = __x_parent->_M_parent;
                    } else {
                        if (__w->_M_right == 0 ||
                            __w->_M_right->_M_color == _S_rb_tree_black) {
                            if (__w->_M_left) __w->_M_left->_M_color = _S_rb_tree_black;
                            __w->_M_color = _S_rb_tree_red;
                            _Rb_tree_rotate_right(__w, __root);
                            __w = __x_parent->_M_right;
                        }
                        __w->_M_color = __x_parent->_M_color;
                        __x_parent->_M_color = _S_rb_tree_black;
                        if (__w->_M_right) __w->_M_right->_M_color = _S_rb_tree_black;
                        _Rb_tree_rotate_left(__x_parent, __root);
                        break;
                    }
                } else {                  // same as above, with _M_right <-> _M_left.
                    _Rb_tree_node_base* __w = __x_parent->_M_left;
                    if (__w->_M_color == _S_rb_tree_red) {
                        __w->_M_color = _S_rb_tree_black;
                        __x_parent->_M_color = _S_rb_tree_red;
                        _Rb_tree_rotate_right(__x_parent, __root);
                        __w = __x_parent->_M_left;
                    }
                    if ((__w->_M_right == 0 ||
                         __w->_M_right->_M_color == _S_rb_tree_black) &&
                        (__w->_M_left == 0 ||
                         __w->_M_left->_M_color == _S_rb_tree_black)) {
                        __w->_M_color = _S_rb_tree_red;
                        __x = __x_parent;
                        __x_parent = __x_parent->_M_parent;
                    } else {
                        if (__w->_M_left == 0 ||
                            __w->_M_left->_M_color == _S_rb_tree_black) {
                            if (__w->_M_right) __w->_M_right->_M_color = _S_rb_tree_black;
                            __w->_M_color = _S_rb_tree_red;
                            _Rb_tree_rotate_left(__w, __root);
                            __w = __x_parent->_M_left;
                        }
                        __w->_M_color = __x_parent->_M_color;
                        __x_parent->_M_color = _S_rb_tree_black;
                        if (__w->_M_left) __w->_M_left->_M_color = _S_rb_tree_black;
                        _Rb_tree_rotate_right(__x_parent, __root);
                        break;
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
        if (_M_node->_M_right != INVALID_ID)
        {
            _M_node = m_pContainer->get_node(_M_node->_M_right);
            while (_M_node->_M_left != INVALID_ID)
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
        else if (_M_node->_M_left != INVALID_ID)
        {
            _Base_ptr __y = m_pContainer->get_node(_M_node->_M_left);
            while (__y->_M_right != INVALID_ID)
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
class NFRbTree : protected NFShmTreeBase<Value, MAX_SIZE>
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

    int &_M_root() const { return (int &) &_M_header->_M_parent; }

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

    int _S_minimum(_Link_type __x)
    {
        while (__x && __x->_M_left != INVALID_ID) __x = get_node(__x->_M_left);
        if (__x)
        {
            return __x->m_self;
        }
    }

    int _S_maximum(_Link_type __x)
    {
        while (__x && __x->_M_right != INVALID_ID) __x = get_node(__x->_M_right);
        if (__x)
        {
            return __x->m_self;
        }
    }

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
    NFRbTree() : _Base(), _M_node_count(0), _M_key_compare()
    {
        _M_empty_initialize();
    }

    NFRbTree(const Compare &__comp) : _Base(), _M_node_count(0), _M_key_compare(__comp)
    {
        _M_empty_initialize();
    }

    ~NFRbTree()
    {
        clear();
    }

    NFRbTree<MAX_SIZE, Key, Value, KeyOfValue, Compare> &
    operator=(const NFRbTree<MAX_SIZE, Key, Value, KeyOfValue, Compare> &__x);

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
            _M_erase(_M_root());
            _M_leftmost() = _M_header;
            _M_root() = 0;
            _M_rightmost() = _M_header;
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
