#ifndef ModelFactory_H_
#define ModelFactory_H_


#include "SWGApplicant.h"
#include "SWGBase.h"
#include "SWGCarrier.h"
#include "SWGCarrierSubsidiary.h"
#include "SWGCounty.h"
#include "SWGCountyBulk.h"
#include "SWGDrug.h"
#include "SWGDrugCoverage.h"
#include "SWGDrugCoverageResponse.h"
#include "SWGDrugPackage.h"
#include "SWGDrugSearchResponse.h"
#include "SWGMeta.h"
#include "SWGNetwork.h"
#include "SWGNetworkSearchResponse.h"
#include "SWGPlan.h"
#include "SWGPlanCounty.h"
#include "SWGPlanCountyBulk.h"
#include "SWGPlanSearchResponse.h"
#include "SWGPlanSearchResult.h"
#include "SWGPlanZipCounty.h"
#include "SWGPricing.h"
#include "SWGProvider.h"
#include "SWGProviderShowResponse.h"
#include "SWGProvidersSearchResponse.h"
#include "SWGRatingArea.h"
#include "SWGRequestPlanFind.h"
#include "SWGRequestPlanFindApplicant.h"
#include "SWGRequestPlanFindProvider.h"
#include "SWGRequestProvidersSearch.h"
#include "SWGState.h"
#include "SWGZipCode.h"
#include "SWGZipCountiesResponse.h"
#include "SWGZipCounty.h"
#include "SWGZipCountyBulk.h"
#include "SWGZipCountyResponse.h"

namespace Swagger {
  inline void* create(QString type) {
    if(QString("SWGApplicant").compare(type) == 0) {
      return new SWGApplicant();
    }
    if(QString("SWGBase").compare(type) == 0) {
      return new SWGBase();
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
    if(QString("SWGCountyBulk").compare(type) == 0) {
      return new SWGCountyBulk();
    }
    if(QString("SWGDrug").compare(type) == 0) {
      return new SWGDrug();
    }
    if(QString("SWGDrugCoverage").compare(type) == 0) {
      return new SWGDrugCoverage();
    }
    if(QString("SWGDrugCoverageResponse").compare(type) == 0) {
      return new SWGDrugCoverageResponse();
    }
    if(QString("SWGDrugPackage").compare(type) == 0) {
      return new SWGDrugPackage();
    }
    if(QString("SWGDrugSearchResponse").compare(type) == 0) {
      return new SWGDrugSearchResponse();
    }
    if(QString("SWGMeta").compare(type) == 0) {
      return new SWGMeta();
    }
    if(QString("SWGNetwork").compare(type) == 0) {
      return new SWGNetwork();
    }
    if(QString("SWGNetworkSearchResponse").compare(type) == 0) {
      return new SWGNetworkSearchResponse();
    }
    if(QString("SWGPlan").compare(type) == 0) {
      return new SWGPlan();
    }
    if(QString("SWGPlanCounty").compare(type) == 0) {
      return new SWGPlanCounty();
    }
    if(QString("SWGPlanCountyBulk").compare(type) == 0) {
      return new SWGPlanCountyBulk();
    }
    if(QString("SWGPlanSearchResponse").compare(type) == 0) {
      return new SWGPlanSearchResponse();
    }
    if(QString("SWGPlanSearchResult").compare(type) == 0) {
      return new SWGPlanSearchResult();
    }
    if(QString("SWGPlanZipCounty").compare(type) == 0) {
      return new SWGPlanZipCounty();
    }
    if(QString("SWGPricing").compare(type) == 0) {
      return new SWGPricing();
    }
    if(QString("SWGProvider").compare(type) == 0) {
      return new SWGProvider();
    }
    if(QString("SWGProviderShowResponse").compare(type) == 0) {
      return new SWGProviderShowResponse();
    }
    if(QString("SWGProvidersSearchResponse").compare(type) == 0) {
      return new SWGProvidersSearchResponse();
    }
    if(QString("SWGRatingArea").compare(type) == 0) {
      return new SWGRatingArea();
    }
    if(QString("SWGRequestPlanFind").compare(type) == 0) {
      return new SWGRequestPlanFind();
    }
    if(QString("SWGRequestPlanFindApplicant").compare(type) == 0) {
      return new SWGRequestPlanFindApplicant();
    }
    if(QString("SWGRequestPlanFindProvider").compare(type) == 0) {
      return new SWGRequestPlanFindProvider();
    }
    if(QString("SWGRequestProvidersSearch").compare(type) == 0) {
      return new SWGRequestProvidersSearch();
    }
    if(QString("SWGState").compare(type) == 0) {
      return new SWGState();
    }
    if(QString("SWGZipCode").compare(type) == 0) {
      return new SWGZipCode();
    }
    if(QString("SWGZipCountiesResponse").compare(type) == 0) {
      return new SWGZipCountiesResponse();
    }
    if(QString("SWGZipCounty").compare(type) == 0) {
      return new SWGZipCounty();
    }
    if(QString("SWGZipCountyBulk").compare(type) == 0) {
      return new SWGZipCountyBulk();
    }
    if(QString("SWGZipCountyResponse").compare(type) == 0) {
      return new SWGZipCountyResponse();
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
