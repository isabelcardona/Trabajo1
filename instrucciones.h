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
unsigned long int LSR(unsigned long int rd,unsigned long int rm);
unsigned long int ADC(unsigned long int rd,unsigned long int rm,unsigned long int c);
void CMN(unsigned long int rd, unsigned long int rm);
void CMP(unsigned long int rd,unsigned long int rm);
void TST(unsigned long int rd, unsigned long int rm);
unsigned long int ADD(unsigned long int rd,unsigned long int rm);
unsigned long int MUL(unsigned long int rd, unsigned long int rm);
unsigned long int SBC(unsigned long int rd, unsigned long int rm, unsigned long int c);
void NOP(unsigned long int rd, unsigned long int rm);
void REV(unsigned long int rd, unsigned long int rm);
void REV16(unsigned long int rd,unsigned long int rm);
unsigned long int ROR(unsigned long int rd, unsigned long int rm, unsigned long int c);
unsigned long int BIC(unsigned long int rd, unsigned long int rm);
unsigned long int MVN(unsigned long int rd,unsigned long int rm);
unsigned long int ASR(unsigned long int rd,unsigned long int rm, unsigned long int c);
