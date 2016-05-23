
#include "SWGDrugCoverageResponse.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGDrugCoverageResponse::SWGDrugCoverageResponse(QString* json) {
    init();
    this->fromJson(*json);
}

SWGDrugCoverageResponse::SWGDrugCoverageResponse() {
    init();
}

SWGDrugCoverageResponse::~SWGDrugCoverageResponse() {
    this->cleanup();
}

void
SWGDrugCoverageResponse::init() {
    meta = new SWGMeta();
drug_coverages = new QList<SWGDrugCoverage*>();
drugs = new QList<SWGDrug*>();
drug_packages = new QList<SWGDrugPackage*>();
}

void
SWGDrugCoverageResponse::cleanup() {
    if(meta != NULL) {
        delete meta;
    }
if(drug_coverages != NULL) {
        QList<SWGDrugCoverage*>* arr = drug_coverages;
        foreach(SWGDrugCoverage* o, *arr) {
            delete o;
        }
        delete drug_coverages;
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

SWGDrugCoverageResponse*
SWGDrugCoverageResponse::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGDrugCoverageResponse::fromJsonObject(QJsonObject &pJson) {
    setValue(&meta, pJson["meta"], "SWGMeta", "SWGMeta");
setValue(&drug_coverages, pJson["drug_coverages"], "QList", "SWGDrugCoverage");
setValue(&drugs, pJson["drugs"], "QList", "SWGDrug");
setValue(&drug_packages, pJson["drug_packages"], "QList", "SWGDrugPackage");
}

QString
SWGDrugCoverageResponse::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGDrugCoverageResponse::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("meta"), meta, obj, QString("SWGMeta"));
    
        

    
    QList<SWGDrugCoverage*>* drug_coveragesList = drug_coverages;
    QJsonArray drug_coveragesJsonArray;
    toJsonArray((QList<void*>*)drug_coverages, &drug_coveragesJsonArray, "drug_coverages", "SWGDrugCoverage");

    obj->insert("drug_coverages", drug_coveragesJsonArray);
    

    
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
SWGDrugCoverageResponse::getMeta() {
    return meta;
}
void
SWGDrugCoverageResponse::setMeta(SWGMeta* meta) {
    this->meta = meta;
}

QList<SWGDrugCoverage*>*
SWGDrugCoverageResponse::getDrugCoverages() {
    return drug_coverages;
}
void
SWGDrugCoverageResponse::setDrugCoverages(QList<SWGDrugCoverage*>* drug_coverages) {
    this->drug_coverages = drug_coverages;
}

QList<SWGDrug*>*
SWGDrugCoverageResponse::getDrugs() {
    return drugs;
}
void
SWGDrugCoverageResponse::setDrugs(QList<SWGDrug*>* drugs) {
    this->drugs = drugs;
}

QList<SWGDrugPackage*>*
SWGDrugCoverageResponse::getDrugPackages() {
    return drug_packages;
}
void
SWGDrugCoverageResponse::setDrugPackages(QList<SWGDrugPackage*>* drug_packages) {
    this->drug_packages = drug_packages;
}



} /* namespace Swagger */

