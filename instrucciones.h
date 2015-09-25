#include <stdio.h>
#include <math.h>
#include <stdint.h>


uint32_t ANDS(uint32_t rd, uint32_t rm, uint32_t* bands );
/**
brief cuncion que realiza una ands
param rd operando 1
param rm operando 2
return un entero con el resultado
**/
uint32_t EORS(uint32_t rd,uint32_t rm, uint32_t* bands );
/**
brief funcion que realiza una xor
param rd operando 1
param rm operando 2
return un entero con el resultado
*/
uint32_t MOVS(uint32_t rd,uint32_t imm, uint32_t* bands );
/**
brief funcion que copia un registro
param rd operando 1
param imm operando 2
return un entero con el resultado
*/
uint32_t ORRS(uint32_t rd,uint32_t rm, uint32_t* bands );
/**
brief funcion que realiza una or
param rd operando 1
param rm operando 2
return un entero con el resultado
*/
uint32_t SUBS(uint32_t rd,uint32_t rm, uint32_t* bands );
/**
brief funcion que resta
param rd operando 1
param rm operando 2
return un entero con el resultado
*/
uint32_t LSLS(uint32_t rd,uint32_t rm, uint32_t imm, uint32_t* bands);
/**
brief funcion que desplaza logica/ hacia la izquierda
param rd operando 1
param rm operando 2
return un entero con el resultado
*/
uint32_t LSRS(uint32_t rd,uint32_t rm, uint32_t imm, uint32_t* bands);
/**
brief funcion que desplaza logica/ hacia la derecha
param rd operando 1
param rm operando 2
return un entero con el resultado
*/
uint32_t ADCS(uint32_t rd,uint32_t rm,uint32_t c, uint32_t* bands);
/**
brief funcion que suma con carry
param rd operando 1
param rm operando 2
param c operando  3
return un entero con el resultado
*/
void CMN(uint32_t rd, uint32_t rm, uint32_t* bands);
/**
brief funcion que suma sin guardar resultado
param rd operando 1
param rm operando 2
no retorna
*/
void CMP(uint32_t rd,uint32_t rm, uint32_t* bands);
/**
brief funcion que resta sin guardar resultado
param rd operando 1
param rm operando 2
no retorna
*/
void TST(uint32_t rd, uint32_t rm, uint32_t* bands);
/**
brief funcion que hace suma lógica sin guardar
param rd operando 1
param rm operando 2
no retorna
*/
uint32_t ADDS(uint32_t rd,uint32_t rm, uint32_t* bands);
/**
brief funcion que suma
param rd operando 1
param rm operando 2
return un entero con el resultado
*/
uint32_t MUL(uint32_t rd, uint32_t rm, uint32_t* bands);
/**
brief funcion que multiplica
param rd operando 1
param rm operando 2
return un entero con el resultado
*/
uint32_t SBC(uint32_t rd, uint32_t rm, uint32_t c, uint32_t* bands);
/**
brief funcion que resta con carry
param rd operando 1
param rm operando 2
param c operando  3
return un entero con el resultado
*/
void NOP(void);
/**
brief funcion negadora
param rd operando 1
param rm operando 2
no retorna
*/
void REV(uint32_t rd, uint32_t rm, uint32_t* bands);
/**
brief funcion que cambia orden de bytes
param rd operando 1
param rm operando 2
no retorna
*/
void REV16(uint32_t rd,uint32_t rm, uint32_t* bands);
/**
brief funcion que cambia orden cada halfword de 16 bytes
param rd operando 1
param rm operando 2
no retorna
*/
uint32_t ROR(uint32_t rd, uint32_t rm, uint32_t x, uint32_t* bands);
/**
brief funcion que rota hacia la derecha
param rd operando 1
param rm operando 2
param c operando  3
return un entero con el resultado
*/
uint32_t BIC(uint32_t rd,uint32_t rm, uint32_t* bands);
/**
brief funcion que realiza operacion and entre un registro y el complemento de otro
param rd operando 1
param rm operando 2
return un entero con el resultado
*/
uint32_t MVN(uint32_t rd,uint32_t rm, uint32_t* bands);
/**
brief funcion que guarda el complemento de un registro
param rd operando 1
param rm operando 2
return un entero con el resultado
*/
uint32_t ASR(uint32_t rd,uint32_t rm,uint32_t x, uint32_t* bands);
/**
brief funcion que hace desplazamiento aritmetico hacia la derecha
param rd operando 1
param rm operando 2
return un entero con el resultado
*/

