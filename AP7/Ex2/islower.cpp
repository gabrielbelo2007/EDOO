#include "islower.h"
#include "../Ex1/product.h"
#include "../Ex1/prefood.h"
#include "../Ex1/freshfood.h"

Product& isLowerCode(Product& pf, Product& ff){
    if (pf.getCode() < ff.getCode()){
        return pf;
    }
    else{
        return ff;
    }
}