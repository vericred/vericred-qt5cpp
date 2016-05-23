
#include "SWGPlanSearchResponse.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGPlanSearchResponse::SWGPlanSearchResponse(QString* json) {
    init();
    this->fromJson(*json);
}

SWGPlanSearchResponse::SWGPlanSearchResponse() {
    init();
}

SWGPlanSearchResponse::~SWGPlanSearchResponse() {
    this->cleanup();
}

void
SWGPlanSearchResponse::init() {
    meta = new SWGMeta();
plans = new QList<SWGPlan*>();
coverages = new QList<SWGDrug*>();
}

void
SWGPlanSearchResponse::cleanup() {
    if(meta != NULL) {
        delete meta;
    }
if(plans != NULL) {
        QList<SWGPlan*>* arr = plans;
        foreach(SWGPlan* o, *arr) {
            delete o;
        }
        delete plans;
    }
if(coverages != NULL) {
        QList<SWGDrug*>* arr = coverages;
        foreach(SWGDrug* o, *arr) {
            delete o;
        }
        delete coverages;
    }
}

SWGPlanSearchResponse*
SWGPlanSearchResponse::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGPlanSearchResponse::fromJsonObject(QJsonObject &pJson) {
    setValue(&meta, pJson["meta"], "SWGMeta", "SWGMeta");
setValue(&plans, pJson["plans"], "QList", "SWGPlan");
setValue(&coverages, pJson["coverages"], "QList", "SWGDrug");
}

QString
SWGPlanSearchResponse::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGPlanSearchResponse::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("meta"), meta, obj, QString("SWGMeta"));
    
        

    
    QList<SWGPlan*>* plansList = plans;
    QJsonArray plansJsonArray;
    toJsonArray((QList<void*>*)plans, &plansJsonArray, "plans", "SWGPlan");

    obj->insert("plans", plansJsonArray);
    

    
    QList<SWGDrug*>* coveragesList = coverages;
    QJsonArray coveragesJsonArray;
    toJsonArray((QList<void*>*)coverages, &coveragesJsonArray, "coverages", "SWGDrug");

    obj->insert("coverages", coveragesJsonArray);
    

    return obj;
}

SWGMeta*
SWGPlanSearchResponse::getMeta() {
    return meta;
}
void
SWGPlanSearchResponse::setMeta(SWGMeta* meta) {
    this->meta = meta;
}

QList<SWGPlan*>*
SWGPlanSearchResponse::getPlans() {
    return plans;
}
void
SWGPlanSearchResponse::setPlans(QList<SWGPlan*>* plans) {
    this->plans = plans;
}

QList<SWGDrug*>*
SWGPlanSearchResponse::getCoverages() {
    return coverages;
}
void
SWGPlanSearchResponse::setCoverages(QList<SWGDrug*>* coverages) {
    this->coverages = coverages;
}



} /* namespace Swagger */

