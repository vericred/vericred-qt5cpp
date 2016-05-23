
#include "SWGZipCountiesResponse.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGZipCountiesResponse::SWGZipCountiesResponse(QString* json) {
    init();
    this->fromJson(*json);
}

SWGZipCountiesResponse::SWGZipCountiesResponse() {
    init();
}

SWGZipCountiesResponse::~SWGZipCountiesResponse() {
    this->cleanup();
}

void
SWGZipCountiesResponse::init() {
    counties = new QList<SWGCounty*>();
states = new QList<SWGState*>();
zip_counties = new QList<SWGZipCounty*>();
zip_codes = new QList<SWGZipCode*>();
}

void
SWGZipCountiesResponse::cleanup() {
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
if(zip_counties != NULL) {
        QList<SWGZipCounty*>* arr = zip_counties;
        foreach(SWGZipCounty* o, *arr) {
            delete o;
        }
        delete zip_counties;
    }
if(zip_codes != NULL) {
        QList<SWGZipCode*>* arr = zip_codes;
        foreach(SWGZipCode* o, *arr) {
            delete o;
        }
        delete zip_codes;
    }
}

SWGZipCountiesResponse*
SWGZipCountiesResponse::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGZipCountiesResponse::fromJsonObject(QJsonObject &pJson) {
    setValue(&counties, pJson["counties"], "QList", "SWGCounty");
setValue(&states, pJson["states"], "QList", "SWGState");
setValue(&zip_counties, pJson["zip_counties"], "QList", "SWGZipCounty");
setValue(&zip_codes, pJson["zip_codes"], "QList", "SWGZipCode");
}

QString
SWGZipCountiesResponse::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGZipCountiesResponse::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    QList<SWGCounty*>* countiesList = counties;
    QJsonArray countiesJsonArray;
    toJsonArray((QList<void*>*)counties, &countiesJsonArray, "counties", "SWGCounty");

    obj->insert("counties", countiesJsonArray);
    

    
    QList<SWGState*>* statesList = states;
    QJsonArray statesJsonArray;
    toJsonArray((QList<void*>*)states, &statesJsonArray, "states", "SWGState");

    obj->insert("states", statesJsonArray);
    

    
    QList<SWGZipCounty*>* zip_countiesList = zip_counties;
    QJsonArray zip_countiesJsonArray;
    toJsonArray((QList<void*>*)zip_counties, &zip_countiesJsonArray, "zip_counties", "SWGZipCounty");

    obj->insert("zip_counties", zip_countiesJsonArray);
    

    
    QList<SWGZipCode*>* zip_codesList = zip_codes;
    QJsonArray zip_codesJsonArray;
    toJsonArray((QList<void*>*)zip_codes, &zip_codesJsonArray, "zip_codes", "SWGZipCode");

    obj->insert("zip_codes", zip_codesJsonArray);
    

    return obj;
}

QList<SWGCounty*>*
SWGZipCountiesResponse::getCounties() {
    return counties;
}
void
SWGZipCountiesResponse::setCounties(QList<SWGCounty*>* counties) {
    this->counties = counties;
}

QList<SWGState*>*
SWGZipCountiesResponse::getStates() {
    return states;
}
void
SWGZipCountiesResponse::setStates(QList<SWGState*>* states) {
    this->states = states;
}

QList<SWGZipCounty*>*
SWGZipCountiesResponse::getZipCounties() {
    return zip_counties;
}
void
SWGZipCountiesResponse::setZipCounties(QList<SWGZipCounty*>* zip_counties) {
    this->zip_counties = zip_counties;
}

QList<SWGZipCode*>*
SWGZipCountiesResponse::getZipCodes() {
    return zip_codes;
}
void
SWGZipCountiesResponse::setZipCodes(QList<SWGZipCode*>* zip_codes) {
    this->zip_codes = zip_codes;
}



} /* namespace Swagger */

