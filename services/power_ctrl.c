#include "power_ctrl.h"

/*Must use real pins*/
SAT_returnState power_control_api(FM_dev_id did, FM_fun_id fid) {


    if(!C_ASSERT(did == OBC_DEV_ID) == true)                                { return SATR_ERROR; }
    if(!C_ASSERT(fid == P_OFF || fid == P_ON || fid == P_RESET) == true)    { return SATR_ERROR; }

    if(did == OBC_SD_DEV_ID && fid == P_ON) {
        HAL_obc_SD_ON();
        return SATR_OK; 
    } else if(did == OBC_SD_DEV_ID && fid == P_OFF) {
        HAL_obc_SD_OFF();
        return SATR_OK;
    } else if(did == OBC_SD_DEV_ID && fid == P_RESET) {
        HAL_obc_SD_OFF();
        //delay
        HAL_obc_SD_ON();
        return SATR_OK;
    }

    return SATR_OK;
}
