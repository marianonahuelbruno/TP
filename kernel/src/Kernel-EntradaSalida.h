#ifndef KERNEL_ENTRADASALIDA_H_
#define KERNEL_ENTRADASALIDA_H_


#include <stdlib.h>
#include <stdio.h>
#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>
#include<readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>

#include <utils/hello.h>
#include "extern_globales.h"


void atender_conexion_ENTRADASALIDA_KERNEL();
void escuchar_a_ENTRADASALIDA();
void enviar_a_ENTRADASALIDA();








#endif /*  KERNEL_ENTRADASALIDA_H_ */
