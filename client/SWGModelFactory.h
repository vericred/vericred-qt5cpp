/**
 * Vericred API
 * Vericred's API allows you to search for Health Plans that a specific doctor
accepts.

## Getting Started

Visit our [Developer Portal](https://vericred.3scale.net) to
create an account.

Once you have created an account, you can create one Application for
Production and another for our Sandbox (select the appropriate Plan when
you create the Application).

## Authentication

To authenticate, pass the API Key you created in the Developer Portal as
a `Vericred-Api-Key` header.

`curl -H 'Vericred-Api-Key: YOUR_KEY' "https://api.vericred.com/providers?search_term=Foo&zip_code=11215"`

## Versioning

Vericred's API default to the latest version.  However, if you need a specific
version, you can request it with an `Accept-Version` header.

The current version is `v3`.  Previous versions are `v1` and `v2`.

`curl -H 'Vericred-Api-Key: YOUR_KEY' -H 'Accept-Version: v2' "https://api.vericred.com/providers?search_term=Foo&zip_code=11215"`

## Pagination

Endpoints that accept `page` and `per_page` parameters are paginated. They expose
four additional fields that contain data about your position in the response,
namely `Total`, `Per-Page`, `Link`, and `Page` as described in [RFC-5988](https://tools.ietf.org/html/rfc5988).

For example, to display 5 results per page and view the second page of a
`GET` to `/networks`, your final request would be `GET /networks?....page=2&per_page=5`.

## Sideloading

When we return multiple levels of an object graph (e.g. `Provider`s and their `State`s
we sideload the associated data.  In this example, we would provide an Array of
`State`s and a `state_id` for each provider.  This is done primarily to reduce the
payload size since many of the `Provider`s will share a `State`

```
{
  providers: [{ id: 1, state_id: 1}, { id: 2, state_id: 1 }],
  states: [{ id: 1, code: 'NY' }]
}
```

If you need the second level of the object graph, you can just match the
corresponding id.

## Selecting specific data

All endpoints allow you to specify which fields you would like to return.
This allows you to limit the response to contain only the data you need.

For example, let's take a request that returns the following JSON by default

```
{
  provider: {
    id: 1,
    name: 'John',
    phone: '1234567890',
    field_we_dont_care_about: 'value_we_dont_care_about'
  },
  states: [{
    id: 1,
    name: 'New York',
    code: 'NY',
    field_we_dont_care_about: 'value_we_dont_care_about'
  }]
}
```

To limit our results to only return the fields we care about, we specify the
`select` query string parameter for the corresponding fields in the JSON
document.

In this case, we want to select `name` and `phone` from the `provider` key,
so we would add the parameters `select=provider.name,provider.phone`.
We also want the `name` and `code` from the `states` key, so we would
add the parameters `select=states.name,staes.code`.  The id field of
each document is always returned whether or not it is requested.

Our final request would be `GET /providers/12345?select=provider.name,provider.phone,states.name,states.code`

The response would be

```
{
  provider: {
    id: 1,
    name: 'John',
    phone: '1234567890'
  },
  states: [{
    id: 1,
    name: 'New York',
    code: 'NY'
  }]
}
```


 *
 * OpenAPI spec version: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
#include "SWGFormulary.h"
#include "SWGFormularyDrugPackageResponse.h"
#include "SWGMeta.h"
#include "SWGNetwork.h"
#include "SWGNetworkSearchResponse.h"
#include "SWGNetworkSize.h"
#include "SWGPlan.h"
#include "SWGPlanCounty.h"
#include "SWGPlanCountyBulk.h"
#include "SWGPlanSearchResponse.h"
#include "SWGPlanSearchResult.h"
#include "SWGPlanShowResponse.h"
#include "SWGPricing.h"
#include "SWGProvider.h"
#include "SWGProviderDetails.h"
#include "SWGProviderShowResponse.h"
#include "SWGProvidersSearchResponse.h"
#include "SWGRatingArea.h"
#include "SWGRequestPlanFind.h"
#include "SWGRequestPlanFindApplicant.h"
#include "SWGRequestPlanFindDrugPackage.h"
#include "SWGRequestPlanFindProvider.h"
#include "SWGRequestProvidersSearch.h"
#include "SWGServiceArea.h"
#include "SWGServiceAreaZipCounty.h"
#include "SWGState.h"
#include "SWGStateNetworkSizeResponse.h"
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
    if(QString("SWGFormulary").compare(type) == 0) {
      return new SWGFormulary();
    }
    if(QString("SWGFormularyDrugPackageResponse").compare(type) == 0) {
      return new SWGFormularyDrugPackageResponse();
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
    if(QString("SWGNetworkSize").compare(type) == 0) {
      return new SWGNetworkSize();
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
    if(QString("SWGPlanShowResponse").compare(type) == 0) {
      return new SWGPlanShowResponse();
    }
    if(QString("SWGPricing").compare(type) == 0) {
      return new SWGPricing();
    }
    if(QString("SWGProvider").compare(type) == 0) {
      return new SWGProvider();
    }
    if(QString("SWGProviderDetails").compare(type) == 0) {
      return new SWGProviderDetails();
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
    if(QString("SWGRequestPlanFindDrugPackage").compare(type) == 0) {
      return new SWGRequestPlanFindDrugPackage();
    }
    if(QString("SWGRequestPlanFindProvider").compare(type) == 0) {
      return new SWGRequestPlanFindProvider();
    }
    if(QString("SWGRequestProvidersSearch").compare(type) == 0) {
      return new SWGRequestProvidersSearch();
    }
    if(QString("SWGServiceArea").compare(type) == 0) {
      return new SWGServiceArea();
    }
    if(QString("SWGServiceAreaZipCounty").compare(type) == 0) {
      return new SWGServiceAreaZipCounty();
    }
    if(QString("SWGState").compare(type) == 0) {
      return new SWGState();
    }
    if(QString("SWGStateNetworkSizeResponse").compare(type) == 0) {
      return new SWGStateNetworkSizeResponse();
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
