#include "productformatcollection.h"

ProductFormatCollection::ProductFormatCollection(){

}

ProductFormatCollection::~ProductFormatCollection(){
    for(std::list<FormatAmount*>::const_iterator it = formatDataList.begin(); it != formatDataList.end(); ++it){
        // delete (*it)->format;
        delete *it;
    }
    formatDataList.clear();
}

int ProductFormatCollection::getFormatAmount(ProductFormat* pfPtr)const{
    if(pfPtr != NULL){ //TODO: pfPtr is always NULL
        for(std::list<FormatAmount*>::const_iterator it = formatDataList.begin(); it != formatDataList.end(); ++it){
            std::string fname = (*it)->format->getName();
            if(fname == pfPtr->getName()){//find corresponding pf
                return (*it)->count;
            }
        }    
    }
    return -1; // get amount failed
}

int ProductFormatCollection::getFormatMaxAmount(ProductFormat* pfPtr) {
    for(std::list<FormatAmount*>::const_iterator it = formatDataList.begin(); it != formatDataList.end(); ++it){
        if((*it)->format->getName() == pfPtr->getName()){//find corresponding pf
            return (*it)->size;
        }
    }   
    return -1; // get amount failed
}

void ProductFormatCollection::addProductFormat(ProductFormat pf){
    FormatAmount* fa = new FormatAmount();
    fa->format = &pf;
    fa->count = DEFAULT_PRODUCT_QUANTITY;
    fa->size = DEFAULT_PRODUCT_SIZE;
    formatDataList.push_back(fa);
}

void ProductFormatCollection::addProductFormat(ProductFormat pf, int c, int s){
    FormatAmount* fa = new FormatAmount();
    fa->format = &pf;
    fa->count = c;
    fa->size = s;
    formatDataList.push_back(fa);
}

//iterate, display productformats
std::string ProductFormatCollection::getFormatNames(){
    std::string retVal = "";
    for(std::list<FormatAmount*>::const_iterator it = formatDataList.begin(); it != formatDataList.end(); ++it){
        retVal += " " + (*it)->format->getName();
    }
    return retVal;
}

void ProductFormatCollection::duplicate(std::string formatName){
    std::list<FormatAmount*>::iterator it;
    for(it = formatDataList.begin(); it != formatDataList.end(); ++it){
        if((*it)->format->getName() == formatName){
            FormatAmount* fa = *it;
            //increase by default quantity
            int quantity = DEFAULT_PRODUCT_QUANTITY; 
            addQuantity(fa, quantity);
        }
    } 
}

void ProductFormatCollection::addQuantity(FormatAmount* format, int quantity){
    format->size += quantity;
    format->count += quantity;
}
