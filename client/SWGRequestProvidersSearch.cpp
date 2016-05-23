
#include "SWGRequestProvidersSearch.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGRequestProvidersSearch::SWGRequestProvidersSearch(QString* json) {
    init();
    this->fromJson(*json);
}

SWGRequestProvidersSearch::SWGRequestProvidersSearch() {
    init();
}

SWGRequestProvidersSearch::~SWGRequestProvidersSearch() {
    this->cleanup();
}

void
SWGRequestProvidersSearch::init() {
    accepts_insurance = false;
hios_ids = new QList<QString*>();
page = NULL;
per_page = NULL;
radius = NULL;
search_term = new QString("");
zip_code = new QString("");
type = new QString("");
}

void
SWGRequestProvidersSearch::cleanup() {
    
if(hios_ids != NULL) {
        QList<QString*>* arr = hios_ids;
        foreach(QString* o, *arr) {
            delete o;
        }
        delete hios_ids;
    }



if(search_term != NULL) {
        delete search_term;
    }
if(zip_code != NULL) {
        delete zip_code;
    }
if(type != NULL) {
        delete type;
    }
}

SWGRequestProvidersSearch*
SWGRequestProvidersSearch::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGRequestProvidersSearch::fromJsonObject(QJsonObject &pJson) {
    setValue(&accepts_insurance, pJson["accepts_insurance"], "bool", "");
setValue(&hios_ids, pJson["hios_ids"], "QList", "QString");
setValue(&page, pJson["page"], "qint32", "");
setValue(&per_page, pJson["per_page"], "qint32", "");
setValue(&radius, pJson["radius"], "qint32", "");
setValue(&search_term, pJson["search_term"], "QString", "QString");
setValue(&zip_code, pJson["zip_code"], "QString", "QString");
setValue(&type, pJson["type"], "QString", "QString");
}

QString
SWGRequestProvidersSearch::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGRequestProvidersSearch::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("accepts_insurance", QJsonValue(accepts_insurance));

    
    QList<QString*>* hios_idsList = hios_ids;
    QJsonArray hios_idsJsonArray;
    toJsonArray((QList<void*>*)hios_ids, &hios_idsJsonArray, "hios_ids", "QString");

    obj->insert("hios_ids", hios_idsJsonArray);
    
obj->insert("page", QJsonValue(page));
obj->insert("per_page", QJsonValue(per_page));
obj->insert("radius", QJsonValue(radius));

    
    toJsonValue(QString("search_term"), search_term, obj, QString("QString"));
    
        

    
    toJsonValue(QString("zip_code"), zip_code, obj, QString("QString"));
    
        

    
    toJsonValue(QString("type"), type, obj, QString("QString"));
    
        

    return obj;
}

bool
SWGRequestProvidersSearch::getAcceptsInsurance() {
    return accepts_insurance;
}
void
SWGRequestProvidersSearch::setAcceptsInsurance(bool accepts_insurance) {
    this->accepts_insurance = accepts_insurance;
}

QList<QString*>*
SWGRequestProvidersSearch::getHiosIds() {
    return hios_ids;
}
void
SWGRequestProvidersSearch::setHiosIds(QList<QString*>* hios_ids) {
    this->hios_ids = hios_ids;
}

qint32
SWGRequestProvidersSearch::getPage() {
    return page;
}
void
SWGRequestProvidersSearch::setPage(qint32 page) {
    this->page = page;
}

qint32
SWGRequestProvidersSearch::getPerPage() {
    return per_page;
}
void
SWGRequestProvidersSearch::setPerPage(qint32 per_page) {
    this->per_page = per_page;
}

qint32
SWGRequestProvidersSearch::getRadius() {
    return radius;
}
void
SWGRequestProvidersSearch::setRadius(qint32 radius) {
    this->radius = radius;
}

QString*
SWGRequestProvidersSearch::getSearchTerm() {
    return search_term;
}
void
SWGRequestProvidersSearch::setSearchTerm(QString* search_term) {
    this->search_term = search_term;
}

QString*
SWGRequestProvidersSearch::getZipCode() {
    return zip_code;
}
void
SWGRequestProvidersSearch::setZipCode(QString* zip_code) {
    this->zip_code = zip_code;
}

QString*
SWGRequestProvidersSearch::getType() {
    return type;
}
void
SWGRequestProvidersSearch::setType(QString* type) {
    this->type = type;
}



} /* namespace Swagger */

