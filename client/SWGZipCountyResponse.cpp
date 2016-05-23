
#include "SWGZipCountyResponse.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGZipCountyResponse::SWGZipCountyResponse(QString* json) {
    init();
    this->fromJson(*json);
}

SWGZipCountyResponse::SWGZipCountyResponse() {
    init();
}

SWGZipCountyResponse::~SWGZipCountyResponse() {
    this->cleanup();
}

void
SWGZipCountyResponse::init() {
    counties = new QList<SWGCounty*>();
states = new QList<SWGState*>();
zip_codes = new QList<SWGZipCode*>();
zip_county = new SWGZipCounty();
}

void
SWGZipCountyResponse::cleanup() {
    if(counties != NULL) {
        QList<SWGCounty*>* arr = counties;
        foreach(SWGCounty* o, *arr) {
            delete o;
        }
        delete counties;
    }
if(states != NULL) {
        QList<SWGState*>* arr = states;
        foreach(SWGState* o, *arr) {
            delete o;
        }
        delete states;
    }
if(zip_codes != NULL) {
        QList<SWGZipCode*>* arr = zip_codes;
        foreach(SWGZipCode* o, *arr) {
            delete o;
        }
        delete zip_codes;
    }
if(zip_county != NULL) {
        delete zip_county;
    }
}

SWGZipCountyResponse*
SWGZipCountyResponse::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGZipCountyResponse::fromJsonObject(QJsonObject &pJson) {
    setValue(&counties, pJson["counties"], "QList", "SWGCounty");
setValue(&states, pJson["states"], "QList", "SWGState");
setValue(&zip_codes, pJson["zip_codes"], "QList", "SWGZipCode");
setValue(&zip_county, pJson["zip_county"], "SWGZipCounty", "SWGZipCounty");
}

QString
SWGZipCountyResponse::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGZipCountyResponse::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    QList<SWGCounty*>* countiesList = counties;
    QJsonArray countiesJsonArray;
    toJsonArray((QList<void*>*)counties, &countiesJsonArray, "counties", "SWGCounty");

    obj->insert("counties", countiesJsonArray);
    

    
    QList<SWGState*>* statesList = states;
    QJsonArray statesJsonArray;
    toJsonArray((QList<void*>*)states, &statesJsonArray, "states", "SWGState");

    obj->insert("states", statesJsonArray);
    

    
    QList<SWGZipCode*>* zip_codesList = zip_codes;
    QJsonArray zip_codesJsonArray;
    toJsonArray((QList<void*>*)zip_codes, &zip_codesJsonArray, "zip_codes", "SWGZipCode");

    obj->insert("zip_codes", zip_codesJsonArray);
    

    
    toJsonValue(QString("zip_county"), zip_county, obj, QString("SWGZipCounty"));
    
        

    return obj;
}

QList<SWGCounty*>*
SWGZipCountyResponse::getCounties() {
    return counties;
}
void
SWGZipCountyResponse::setCounties(QList<SWGCounty*>* counties) {
    this->counties = counties;
}

QList<SWGState*>*
SWGZipCountyResponse::getStates() {
    return states;
}
void
SWGZipCountyResponse::setStates(QList<SWGState*>* states) {
    this->states = states;
}

QList<SWGZipCode*>*
SWGZipCountyResponse::getZipCodes() {
    return zip_codes;
}
void
SWGZipCountyResponse::setZipCodes(QList<SWGZipCode*>* zip_codes) {
    this->zip_codes = zip_codes;
}

SWGZipCounty*
SWGZipCountyResponse::getZipCounty() {
    return zip_county;
}
void
SWGZipCountyResponse::setZipCounty(SWGZipCounty* zip_county) {
    this->zip_county = zip_county;
}



} /* namespace Swagger */

