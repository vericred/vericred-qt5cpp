
#include "SWGDrugSearchResponse.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGDrugSearchResponse::SWGDrugSearchResponse(QString* json) {
    init();
    this->fromJson(*json);
}

SWGDrugSearchResponse::SWGDrugSearchResponse() {
    init();
}

SWGDrugSearchResponse::~SWGDrugSearchResponse() {
    this->cleanup();
}

void
SWGDrugSearchResponse::init() {
    meta = new SWGMeta();
drugs = new QList<SWGDrug*>();
drug_packages = new QList<SWGDrugPackage*>();
}

void
SWGDrugSearchResponse::cleanup() {
    if(meta != NULL) {
        delete meta;
    }
if(drugs != NULL) {
        QList<SWGDrug*>* arr = drugs;
        foreach(SWGDrug* o, *arr) {
            delete o;
        }
        delete drugs;
    }
if(drug_packages != NULL) {
        QList<SWGDrugPackage*>* arr = drug_packages;
        foreach(SWGDrugPackage* o, *arr) {
            delete o;
        }
        delete drug_packages;
    }
}

SWGDrugSearchResponse*
SWGDrugSearchResponse::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGDrugSearchResponse::fromJsonObject(QJsonObject &pJson) {
    setValue(&meta, pJson["meta"], "SWGMeta", "SWGMeta");
setValue(&drugs, pJson["drugs"], "QList", "SWGDrug");
setValue(&drug_packages, pJson["drug_packages"], "QList", "SWGDrugPackage");
}

QString
SWGDrugSearchResponse::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGDrugSearchResponse::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("meta"), meta, obj, QString("SWGMeta"));
    
        

    
    QList<SWGDrug*>* drugsList = drugs;
    QJsonArray drugsJsonArray;
    toJsonArray((QList<void*>*)drugs, &drugsJsonArray, "drugs", "SWGDrug");

    obj->insert("drugs", drugsJsonArray);
    

    
    QList<SWGDrugPackage*>* drug_packagesList = drug_packages;
    QJsonArray drug_packagesJsonArray;
    toJsonArray((QList<void*>*)drug_packages, &drug_packagesJsonArray, "drug_packages", "SWGDrugPackage");

    obj->insert("drug_packages", drug_packagesJsonArray);
    

    return obj;
}

SWGMeta*
SWGDrugSearchResponse::getMeta() {
    return meta;
}
void
SWGDrugSearchResponse::setMeta(SWGMeta* meta) {
    this->meta = meta;
}

QList<SWGDrug*>*
SWGDrugSearchResponse::getDrugs() {
    return drugs;
}
void
SWGDrugSearchResponse::setDrugs(QList<SWGDrug*>* drugs) {
    this->drugs = drugs;
}

QList<SWGDrugPackage*>*
SWGDrugSearchResponse::getDrugPackages() {
    return drug_packages;
}
void
SWGDrugSearchResponse::setDrugPackages(QList<SWGDrugPackage*>* drug_packages) {
    this->drug_packages = drug_packages;
}



} /* namespace Swagger */

