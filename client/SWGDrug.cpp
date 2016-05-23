
#include "SWGDrug.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGDrug::SWGDrug(QString* json) {
    init();
    this->fromJson(*json);
}

SWGDrug::SWGDrug() {
    init();
}

SWGDrug::~SWGDrug() {
    this->cleanup();
}

void
SWGDrug::init() {
    id = new QString("");
proprietary_name = new QString("");
non_proprietary_name = new QString("");
drug_package_ids = new QList<QString*>();
}

void
SWGDrug::cleanup() {
    if(id != NULL) {
        delete id;
    }
if(proprietary_name != NULL) {
        delete proprietary_name;
    }
if(non_proprietary_name != NULL) {
        delete non_proprietary_name;
    }
if(drug_package_ids != NULL) {
        QList<QString*>* arr = drug_package_ids;
        foreach(QString* o, *arr) {
            delete o;
        }
        delete drug_package_ids;
    }
}

SWGDrug*
SWGDrug::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGDrug::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "QString", "QString");
setValue(&proprietary_name, pJson["proprietary_name"], "QString", "QString");
setValue(&non_proprietary_name, pJson["non_proprietary_name"], "QString", "QString");
setValue(&drug_package_ids, pJson["drug_package_ids"], "QList", "QString");
}

QString
SWGDrug::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGDrug::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("id"), id, obj, QString("QString"));
    
        

    
    toJsonValue(QString("proprietary_name"), proprietary_name, obj, QString("QString"));
    
        

    
    toJsonValue(QString("non_proprietary_name"), non_proprietary_name, obj, QString("QString"));
    
        

    
    QList<QString*>* drug_package_idsList = drug_package_ids;
    QJsonArray drug_package_idsJsonArray;
    toJsonArray((QList<void*>*)drug_package_ids, &drug_package_idsJsonArray, "drug_package_ids", "QString");

    obj->insert("drug_package_ids", drug_package_idsJsonArray);
    

    return obj;
}

QString*
SWGDrug::getId() {
    return id;
}
void
SWGDrug::setId(QString* id) {
    this->id = id;
}

QString*
SWGDrug::getProprietaryName() {
    return proprietary_name;
}
void
SWGDrug::setProprietaryName(QString* proprietary_name) {
    this->proprietary_name = proprietary_name;
}

QString*
SWGDrug::getNonProprietaryName() {
    return non_proprietary_name;
}
void
SWGDrug::setNonProprietaryName(QString* non_proprietary_name) {
    this->non_proprietary_name = non_proprietary_name;
}

QList<QString*>*
SWGDrug::getDrugPackageIds() {
    return drug_package_ids;
}
void
SWGDrug::setDrugPackageIds(QList<QString*>* drug_package_ids) {
    this->drug_package_ids = drug_package_ids;
}



} /* namespace Swagger */

