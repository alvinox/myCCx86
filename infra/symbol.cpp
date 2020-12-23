#include "symbol.h"

/*******************************************************************************
                                   class Var
*******************************************************************************/

Var::Var(bool ext, Tag t, bool ptr, const std::string& name, Var* init) {
    clear();
    setExtern(ext);
    setType(t);
    setPtr(ptr);
    setName(name);
    _initData = init;
}

Var::Var(bool ext, Tag t, const std::string& name, int len) {
    clear();
    setExtern(ext);
    setType(t);
    setName(name);
    setArray(len);
}

void Var::setName(const std::string& n) {
    if (n == "") {
        // TODO
    } else {
        _name = n;
    }
}

void Var::setPtr(bool ptr) {
    if (!ptr)
        return;

    _isPtr = true;
    if (!_externed) {
        _size = 4; // point is 4 bytes
    }
}

void Var::setArray(int len) {
    if (len < 0) {
        SEMERROR(ARRAY_LEN_INVALID, _name);//数组长度小于等于0错误
    } else {
        _isArray = true;
        _isLeft  = false;
        _arraySize = len;
        if (!_externed) {
            _size = _size * len;
        }
        
    }
}

void Var::clear() {
    _externed     = false;
    _type         = IDENTIFER;
    _isPtr        = false;
    _isArray      = false;
    _isLeft       = false;
    _arraySize    = 0;
    _size         = 0;
}
/*******************************************************************************
                                   class Fun
*******************************************************************************/

Fun::Fun(bool ext, Tag t, const std::string& name, const std::vector<Var*>& paraList) 
    : _externed(ext), _type(t), _name(name), _paraVar(paraList) {
}

Fun::~Fun() {

}