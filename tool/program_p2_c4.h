#ifndef PROGRAM_P2_C4_H
#define PROGRAM_P2_C4_H

#include "programid.h"

class PROGRAM_P2_C4 : public ProgramId
{
public:
    typedef int attribute;
    typedef int uniform;
public:
    attribute   _position;
    attribute   _normal;
    uniform     _colorLight;
    uniform     _colorOffset;
    uniform     _MVP;
    uniform     _lightDir;
    uniform     _matMV;
    uniform     _fogR;
    uniform     _fogDensity;
    uniform     _fogColor;
public:
    PROGRAM_P2_C4();
    /// 初始化函数
    virtual bool    initialize();

    /**
    *   使用程序
    */
    virtual void    begin();
    /**
    *   使用完成
    */
    virtual void    end();
};

#endif // PROGRAM_P2_C4_H
