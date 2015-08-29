unsigned long int ands(unsigned long int rd, unsigned long int rm );
/**
*\brief funcion que multiplica
*\param rd operando 1
*\param rm operando 2
*\return un entero con el resultado
*/
unsigned long int eors(unsigned long int rd,unsigned long int rm );
/**
*\brief funcion que realiza una xor
*\param rd operando 1
*\param rm operando 2
*\return un entero con el resultado
*/
unsigned long int movs(unsigned long int rd,unsigned long int imm );
/**
*\brief funcion que copia un registro
*\param rd operando 1
*\param imm operando 2
*\return un entero con el resultado
*/
unsigned long int orrs(unsigned long int rd,unsigned long int rm );
/**
*\brief funcion que realiza una or
*\param rd operando 1
*\param rm operando 2
*\return un entero con el resultado
*/
unsigned long int subs(unsigned long int rd,unsigned long int rm );
/**
*\brief funcion que resta
*\param rd operando 1
*\param rm operando 2
*\return un entero con el resultado
*/
unsigned long int LSLS(unsigned long int rd,unsigned long int rm);
/**
*\brief funcion que desplaza logica/ hacia la izquierda
*\param rd operando 1
*\param rm operando 2
*\return un entero con el resultado
*/
unsigned long int LSR(unsigned long int rd,unsigned long int rm);
/**
*\brief funcion que desplaza logica/ hacia la derecha
*\param rd operando 1
*\param rm operando 2
*\return un entero con el resultado
*/
unsigned long int ADC(unsigned long int rd,unsigned long int rm,unsigned long int c);
/**
*\brief funcion que suma con carry
*\param rd operando 1
*\param rm operando 2
*\param c operando  3
*\return un entero con el resultado
*/
void CMN(unsigned long int rd, unsigned long int rm);
/**
*\brief funcion que suma sin guardar resultado
*\param rd operando 1
*\param rm operando 2
*\no retorna
*/
void CMP(unsigned long int rd,unsigned long int rm);
/**
*\brief funcion que resta sin guardar resultado
*\param rd operando 1
*\param rm operando 2
*\no retorna
*/
void TST(unsigned long int rd, unsigned long int rm);
/**
*\brief funcion que hace suma lógica sin guardar
*\param rd operando 1
*\param rm operando 2
*\no retorna
*/
unsigned long int ADD(unsigned long int rd,unsigned long int rm);
/**
*\brief funcion que suma
*\param rd operando 1
*\param rm operando 2
*\return un entero con el resultado
*/
unsigned long int MUL(unsigned long int rd, unsigned long int rm);
/**
*\brief funcion que multiplica
*\param rd operando 1
*\param rm operando 2
*\return un entero con el resultado
*/
unsigned long int SBC(unsigned long int rd, unsigned long int rm, unsigned long int c);
/**
*\brief funcion que resta con carry
*\param rd operando 1
*\param rm operando 2
*\param c operando  3
*\return un entero con el resultado
*/
void NOP(unsigned long int rd, unsigned long int rm);
/**
*\brief funcion negadora
*\param rd operando 1
*\param rm operando 2
*\no retorna
*/
void REV(unsigned long int rd, unsigned long int rm);
/**
*\brief funcion que cambia orden de bytes
*\param rd operando 1
*\param rm operando 2
*\no retorna
*/
void REV16(unsigned long int rd,unsigned long int rm);
/**
*\brief funcion que cambia orden cada halfword de 16 bytes
*\param rd operando 1
*\param rm operando 2
*\no retorna
*/
unsigned long int ROR(unsigned long int rd, unsigned long int rm, unsigned long int c);
/**
*\brief funcion que rota hacia la derecha
*\param rd operando 1
*\param rm operando 2
*\param c operando  3
*\return un entero con el resultado
*/
unsigned long int BIC(unsigned long int rd, unsigned long int rm);
/**
*\brief funcion que realiza operacion and entre un registro y el complemento de otro
*\param rd operando 1
*\param rm operando 2
*\return un entero con el resultado
*/
unsigned long int MVN(unsigned long int rd,unsigned long int rm);
/**
*\brief funcion que guarda el complemento de un registro
*\param rd operando 1
*\param rm operando 2
*\return un entero con el resultado
*/
unsigned long int ASR(unsigned long int rd,unsigned long int rm, unsigned long int c);
/**
*\brief funcion que hace desplazamiento aritmetico hacia la derecha
*\param rd operando 1
*\param rm operando 2
*\return un entero con el resultado
*/

