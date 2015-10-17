void NVIC(uint32_t* interrup_regs, uint32_t* flash_mem, uint32_t* regs, uint32_t* bands, uint32_t* mem);
/**
\brief funcion que detecta una interrupcion y la ejecuta
\param interrup_regs contiene los registros de las interrupciones
\param flash_mem  contiene la memoria
\param regs contiene los registros
\param bands contiene las banderas
\no retorna
*/