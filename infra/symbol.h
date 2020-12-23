#ifndef __SYMBOL_H_
#define __SYMBOL_H_

#include "common.h"
#include "error.h"
#include "token.h"

class Var {
  public:
    Var(bool ext, Tag t, bool ptr, const std::string& name, Var* init = NULL);
    Var(bool ext, Tag t, const std::string& name, int len);
    ~Var() { }
  public:
    void setExtern(bool ext) { _externed = ext; }
    bool getExtern() const { return _externed; }
    void setType(Tag t) { _type = t; }
    Tag getType() const { return _type; }
    void setName(const std::string& n);
    std::string getName() const { return _name; }
    void setPtr(bool ptr);
    bool isPtr() const { return _isPtr; }
    void setArray(int len);
    bool isArray() const { return _isArray; }
    void setLeft(bool left) { _isLeft = left; }
    bool getLeft() const { return _isLeft; }

    void clear();
  private:
    Tag  _type;
    std::string _name;
    bool _externed;
    bool _isPtr;
    bool _isArray;
    bool _isLeft;

    int  _arraySize;
    int _size;

    Var* _initData;
};

class Fun {
  public:
    Fun(bool ext, Tag t, const std::string& name, const std::vector<Var*>& paraList);
    ~Fun();
  public:
    bool getExtern() const { return _externed; }
    void setExtern(bool ext) { _externed = ext; }
    Tag getType() const { return _type; }
    const std::string& getName() const { return _name; }
    const std::vector<Var*>& getParaVar() const { return _paraVar; }
  private:
    bool _externed;
    Tag  _type;
    std::string _name;
    std::vector<Var*> _paraVar;
};

#endif // __SYMBOL_H_