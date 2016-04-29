
#include "SWGInline_response_200_2.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGInline_response_200_2::SWGInline_response_200_2(QString* json) {
    init();
    this->fromJson(*json);
}

SWGInline_response_200_2::SWGInline_response_200_2() {
    init();
}

SWGInline_response_200_2::~SWGInline_response_200_2() {
    this->cleanup();
}

void
SWGInline_response_200_2::init() {
    zip_counties = new QList<SWGZipCounty*>();
counties = new QList<SWGCounty*>();
zip_codes = new QList<SWGZipCode*>();
}

void
SWGInline_response_200_2::cleanup() {
    if(zip_counties != NULL) {
        QList<SWGZipCounty*>* arr = zip_counties;
        foreach(SWGZipCounty* o, *arr) {
            delete o;
        }
        delete zip_counties;
    }
if(counties != NULL) {
        QList<SWGCounty*>* arr = counties;
        foreach(SWGCounty* o, *arr) {
            delete o;
        }
        delete counties;
    }
if(zip_codes != NULL) {
        QList<SWGZipCode*>* arr = zip_codes;
        foreach(SWGZipCode* o, *arr) {
            delete o;
        }
        delete zip_codes;
    }
}

SWGInline_response_200_2*
SWGInline_response_200_2::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGInline_response_200_2::fromJsonObject(QJsonObject &pJson) {
    setValue(&zip_counties, pJson["zip_counties"], "QList", "SWGZipCounty");
setValue(&counties, pJson["counties"], "QList", "SWGCounty");
setValue(&zip_codes, pJson["zip_codes"], "QList", "SWGZipCode");
}

QString
SWGInline_response_200_2::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGInline_response_200_2::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    QList<SWGZipCounty*>* zip_countiesList = zip_counties;
    QJsonArray zip_countiesJsonArray;
    toJsonArray((QList<void*>*)zip_counties, &zip_countiesJsonArray, "zip_counties", "SWGZipCounty");

    obj->insert("zip_counties", zip_countiesJsonArray);
    

    
    QList<SWGCounty*>* countiesList = counties;
    QJsonArray countiesJsonArray;
    toJsonArray((QList<void*>*)counties, &countiesJsonArray, "counties", "SWGCounty");

    obj->insert("counties", countiesJsonArray);
    

    
    QList<SWGZipCode*>* zip_codesList = zip_codes;
    QJsonArray zip_codesJsonArray;
    toJsonArray((QList<void*>*)zip_codes, &zip_codesJsonArray, "zip_codes", "SWGZipCode");

    obj->insert("zip_codes", zip_codesJsonArray);
    

    return obj;
}

QList<SWGZipCounty*>*
SWGInline_response_200_2::getZipCounties() {
    return zip_counties;
}
void
SWGInline_response_200_2::setZipCounties(QList<SWGZipCounty*>* zip_counties) {
    this->zip_counties = zip_counties;
}

QList<SWGCounty*>*
SWGInline_response_200_2::getCounties() {
    return counties;
}
void
SWGInline_response_200_2::setCounties(QList<SWGCounty*>* counties) {
    this->counties = counties;
}

QList<SWGZipCode*>*
SWGInline_response_200_2::getZipCodes() {
    return zip_codes;
}
void
SWGInline_response_200_2::setZipCodes(QList<SWGZipCode*>* zip_codes) {
    this->zip_codes = zip_codes;
}



} /* namespace Swagger */

