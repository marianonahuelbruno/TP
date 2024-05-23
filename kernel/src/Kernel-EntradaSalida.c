#include "Kernel-EntradaSalida.h"

void atender_conexion_ENTRADASALIDA_KERNEL(){



    pthread_t hilo_enviar_ENTRADASALIDA_KERNEL;
    pthread_create(&hilo_enviar_ENTRADASALIDA_KERNEL,NULL,(void*)enviar_a_ENTRADASALIDA,NULL);
    pthread_detach( hilo_enviar_ENTRADASALIDA_KERNEL);

    
    pthread_t hilo_escucha_ENTRADASALIDA_KERNEL;
    pthread_create(&hilo_escucha_ENTRADASALIDA_KERNEL,NULL,(void*)escuchar_a_ENTRADASALIDA,NULL);
    pthread_join(hilo_escucha_ENTRADASALIDA_KERNEL,NULL);

}


void enviar_a_ENTRADASALIDA(){

    enviar_mensaje("KERNEL",fd_entradaSalida);
    
    while (1){
        paquete(fd_entradaSalida);
}
}




void escuchar_a_ENTRADASALIDA(){
    bool continuarIterando=1;
    t_list* lista;    
        while (continuarIterando) {
            int cod_op = recibir_operacion(fd_entradaSalida);
            switch (cod_op) {
            case HANDSHAKE:
                recibir_mensaje(fd_entradaSalida, logger_kernel);
                break;
            case PAQUETE:
                lista = recibir_paquete(fd_entradaSalida);
                log_info(logger_kernel_db, "Me llegaron los siguientes valores:\n");
                list_logger(lista,logger_kernel_db);
                break;
            case -1:
                log_error(logger_kernel_db, "La ENTRADASALIDA SE DESCONECTO. Terminando servidor");
                continuarIterando=0;
                break;
            default:
                log_warning(logger_kernel_db,"Operacion desconocida de ENTRADASALIDA. No quieras meter la pata");
                break;
            }
        }


}








