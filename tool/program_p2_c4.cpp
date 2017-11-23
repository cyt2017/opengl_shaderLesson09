#include "program_p2_c4.h"

PROGRAM_P2_C4::PROGRAM_P2_C4()
{
    _position       =   -1;
    _normal         =   -1;
    _colorLight     =   -1;
    _colorOffset    =   -1;
    _MVP            =   -1;
    _lightDir       =   -1;
    _matMV          =   -1;
    _fogR           =   -1;
    _fogDensity     =   -1;
    _fogColor       =   -1;
}

bool PROGRAM_P2_C4::initialize()
{
    //!
    //!
    //!
    //!
    //!
    const char* vs  =
    {
        "uniform    mat4    _MVP;"
        "uniform    mat4    _matMV;"
        "uniform    vec3    _lightDir;"
        "uniform    vec3    _colorLight;"
        "uniform    vec3    _colorOffset;"
        "uniform    float   _fogR;"
        "uniform    float   _fogDensity;"
        "attribute  vec3    _position;"
        "attribute  vec3    _normal;"
        "varying    vec4    _outColor;"
        "varying    float   _outFog;"
        "void main()"
        "{"
        "   float NDotL =   max(dot(_normal, _lightDir), 0.0);"
        "   _outColor   =   vec4(_colorLight*NDotL + _colorOffset,1.0);"
        "   vec3 viewPos=   (_matMV*vec4(_position,1.0)).xyz;"
        "   float len   =   length(viewPos);"
        "   _outFog     =   (_fogR - len)*_fogDensity;"
        "   _outFog     =   clamp(_outFog, 0.0, 1.0);"
        "   gl_Position =   _MVP * vec4(_position,1.0);"
        "}"
    };
    const char* ps  =
    {
        "precision  lowp    float; "
        "uniform    vec4    _fogColor;"
        "varying    vec4    _outColor;"
        "varying    float   _outFog;"
        "void main()"
        "{"
        "   gl_FragColor    =   mix(_outColor,_fogColor,_outFog);"
        "}"
    };
    bool    res =   createProgram(vs,ps);
    if(res)
    {
        _position   =   glGetAttribLocation(_programId,"_position");
        _normal     =   glGetAttribLocation(_programId,"_normal");
        _colorLight =   glGetUniformLocation(_programId,"_colorLight");
        _colorOffset=   glGetUniformLocation(_programId,"_colorOffset");
        _matMV      =   glGetUniformLocation(_programId,"_matMV");
        _MVP        =   glGetUniformLocation(_programId,"_MVP");
        _lightDir   =   glGetUniformLocation(_programId,"_lightDir");
        _fogR       =   glGetUniformLocation(_programId,"_fogR");
        _fogDensity =   glGetUniformLocation(_programId,"_fogDensity");
        _fogColor   =   glGetUniformLocation(_programId,"_fogColor");
    }
    return  res;
}

void PROGRAM_P2_C4::begin()
{
    glUseProgram(_programId);
    //!在显卡里面使用的局部变量，在使用时是需要进行使能和关闭的
    glEnableVertexAttribArray(_position);       
    glEnableVertexAttribArray(_normal);
}

void PROGRAM_P2_C4::end()
{
    glDisableVertexAttribArray(_position);
    glDisableVertexAttribArray(_normal);
    glUseProgram(0);
}
