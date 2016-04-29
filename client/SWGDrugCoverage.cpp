
#include "SWGDrugCoverage.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGDrugCoverage::SWGDrugCoverage(QString* json) {
    init();
    this->fromJson(*json);
}

SWGDrugCoverage::SWGDrugCoverage() {
    init();
}

SWGDrugCoverage::~SWGDrugCoverage() {
    this->cleanup();
}

void
SWGDrugCoverage::init() {
    plan_id = new QString("");
ndc_package_code = new QString("");
tier = new QString("");
quantity_limit = false;
prior_authorization = false;
step_therapy = false;
}

void
SWGDrugCoverage::cleanup() {
    if(plan_id != NULL) {
        delete plan_id;
    }
if(ndc_package_code != NULL) {
        delete ndc_package_code;
    }
if(tier != NULL) {
        delete tier;
    }



}

SWGDrugCoverage*
SWGDrugCoverage::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGDrugCoverage::fromJsonObject(QJsonObject &pJson) {
    setValue(&plan_id, pJson["plan_id"], "QString", "QString");
setValue(&ndc_package_code, pJson["ndc_package_code"], "QString", "QString");
setValue(&tier, pJson["tier"], "QString", "QString");
setValue(&quantity_limit, pJson["quantity_limit"], "bool", "");
setValue(&prior_authorization, pJson["prior_authorization"], "bool", "");
setValue(&step_therapy, pJson["step_therapy"], "bool", "");
}

QString
SWGDrugCoverage::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGDrugCoverage::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("plan_id"), plan_id, obj, QString("QString"));
    
        

    
    toJsonValue(QString("ndc_package_code"), ndc_package_code, obj, QString("QString"));
    
        

    
    toJsonValue(QString("tier"), tier, obj, QString("QString"));
    
        
obj->insert("quantity_limit", QJsonValue(quantity_limit));
obj->insert("prior_authorization", QJsonValue(prior_authorization));
obj->insert("step_therapy", QJsonValue(step_therapy));

    return obj;
}

QString*
SWGDrugCoverage::getPlanId() {
    return plan_id;
}
void
SWGDrugCoverage::setPlanId(QString* plan_id) {
    this->plan_id = plan_id;
}

QString*
SWGDrugCoverage::getNdcPackageCode() {
    return ndc_package_code;
}
void
SWGDrugCoverage::setNdcPackageCode(QString* ndc_package_code) {
    this->ndc_package_code = ndc_package_code;
}

QString*
SWGDrugCoverage::getTier() {
    return tier;
}
void
SWGDrugCoverage::setTier(QString* tier) {
    this->tier = tier;
}

bool
SWGDrugCoverage::getQuantityLimit() {
    return quantity_limit;
}
void
SWGDrugCoverage::setQuantityLimit(bool quantity_limit) {
    this->quantity_limit = quantity_limit;
}

bool
SWGDrugCoverage::getPriorAuthorization() {
    return prior_authorization;
}
void
SWGDrugCoverage::setPriorAuthorization(bool prior_authorization) {
    this->prior_authorization = prior_authorization;
}

bool
SWGDrugCoverage::getStepTherapy() {
    return step_therapy;
}
void
SWGDrugCoverage::setStepTherapy(bool step_therapy) {
    this->step_therapy = step_therapy;
}



} /* namespace Swagger */

