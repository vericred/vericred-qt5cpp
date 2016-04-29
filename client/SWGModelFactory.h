#ifndef ModelFactory_H_
#define ModelFactory_H_


#include "SWGApplicant.h"
#include "SWGCarrier.h"
#include "SWGCarrierSubsidiary.h"
#include "SWGCounty.h"
#include "SWGDrug.h"
#include "SWGDrugCoverage.h"
#include "SWGInline_response_200.h"
#include "SWGInline_response_200_1.h"
#include "SWGInline_response_200_2.h"
#include "SWGPlan.h"
#include "SWGPlanCounty.h"
#include "SWGPlanSearchResult.h"
#include "SWGPricing.h"
#include "SWGProvider.h"
#include "SWGQuery.h"
#include "SWGRatingArea.h"
#include "SWGState.h"
#include "SWGZipCode.h"
#include "SWGZipCounty.h"

namespace Swagger {
  inline void* create(QString type) {
    if(QString("SWGApplicant").compare(type) == 0) {
      return new SWGApplicant();
    }
    if(QString("SWGCarrier").compare(type) == 0) {
      return new SWGCarrier();
    }
    if(QString("SWGCarrierSubsidiary").compare(type) == 0) {
      return new SWGCarrierSubsidiary();
    }
    if(QString("SWGCounty").compare(type) == 0) {
      return new SWGCounty();
    }
    if(QString("SWGDrug").compare(type) == 0) {
      return new SWGDrug();
    }
    if(QString("SWGDrugCoverage").compare(type) == 0) {
      return new SWGDrugCoverage();
    }
    if(QString("SWGInline_response_200").compare(type) == 0) {
      return new SWGInline_response_200();
    }
    if(QString("SWGInline_response_200_1").compare(type) == 0) {
      return new SWGInline_response_200_1();
    }
    if(QString("SWGInline_response_200_2").compare(type) == 0) {
      return new SWGInline_response_200_2();
    }
    if(QString("SWGPlan").compare(type) == 0) {
      return new SWGPlan();
    }
    if(QString("SWGPlanCounty").compare(type) == 0) {
      return new SWGPlanCounty();
    }
    if(QString("SWGPlanSearchResult").compare(type) == 0) {
      return new SWGPlanSearchResult();
    }
    if(QString("SWGPricing").compare(type) == 0) {
      return new SWGPricing();
    }
    if(QString("SWGProvider").compare(type) == 0) {
      return new SWGProvider();
    }
    if(QString("SWGQuery").compare(type) == 0) {
      return new SWGQuery();
    }
    if(QString("SWGRatingArea").compare(type) == 0) {
      return new SWGRatingArea();
    }
    if(QString("SWGState").compare(type) == 0) {
      return new SWGState();
    }
    if(QString("SWGZipCode").compare(type) == 0) {
      return new SWGZipCode();
    }
    if(QString("SWGZipCounty").compare(type) == 0) {
      return new SWGZipCounty();
    }
    
    return NULL;
  }

  inline void* create(QString json, QString type) {
    void* val = create(type);
    if(val != NULL) {
      SWGObject* obj = static_cast<SWGObject*>(val);
      return obj->fromJson(json);
    }
    if(type.startsWith("QString")) {
      return new QString();
    }
    return NULL;
  }
} /* namespace Swagger */

#endif /* ModelFactory_H_ */
