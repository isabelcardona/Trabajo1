void mostrar_registros(uint32_t* regs, uint32_t* bands);
/**
\brief funcion que muestra los registros
\param regs  contiene los registros
\param bands  contiene las banderas
\no retorna
*/

void mostrar_sram(uint32_t* mem, uint32_t* addr);
/**
\brief funcion que muestra la memoria
\param mem arreglo para la Sram
\param addr contiene las direcciones corespondientes a la memoria.
\no retorna  
*/
void mostrar_iomem(uint32_t* in_out, uint32_t* addr_inout);
/**
\brief funcion que muestra los puertos de entrada y salida
\param int_out contiene las entradas y salidas
\param addr_inout contiene las direcciones de las entradas y salidas 
\no retorna 
*/
