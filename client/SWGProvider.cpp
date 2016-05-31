
#include "SWGProvider.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGProvider::SWGProvider(QString* json) {
    init();
    this->fromJson(*json);
}

SWGProvider::SWGProvider() {
    init();
}

SWGProvider::~SWGProvider() {
    this->cleanup();
}

void
SWGProvider::init() {
    accepting_change_of_payor_patients = false;
accepting_medicaid_patients = false;
accepting_medicare_patients = false;
accepting_private_patients = false;
accepting_referral_patients = false;
city = new QString("");
email = new QString("");
gender = new QString("");
first_name = new QString("");
hios_ids = new QList<QString*>();
id = NULL;
last_name = new QString("");
latitude = 0.0;
longitude = 0.0;
middle_name = new QString("");
network_ids = new QList<qint32>();
personal_phone = new QString("");
phone = new QString("");
presentation_name = new QString("");
specialty = new QString("");
state = new QString("");
state_id = NULL;
street_line_1 = new QString("");
street_line_2 = new QString("");
suffix = new QString("");
title = new QString("");
type = new QString("");
zip_code = new QString("");
}

void
SWGProvider::cleanup() {
    




if(city != NULL) {
        delete city;
    }
if(email != NULL) {
        delete email;
    }
if(gender != NULL) {
        delete gender;
    }
if(first_name != NULL) {
        delete first_name;
    }
if(hios_ids != NULL) {
        QList<QString*>* arr = hios_ids;
        foreach(QString* o, *arr) {
            delete o;
        }
        delete hios_ids;
    }

if(last_name != NULL) {
        delete last_name;
    }
if(latitude != NULL) {
        delete latitude;
    }
if(longitude != NULL) {
        delete longitude;
    }
if(middle_name != NULL) {
        delete middle_name;
    }

if(personal_phone != NULL) {
        delete personal_phone;
    }
if(phone != NULL) {
        delete phone;
    }
if(presentation_name != NULL) {
        delete presentation_name;
    }
if(specialty != NULL) {
        delete specialty;
    }
if(state != NULL) {
        delete state;
    }

if(street_line_1 != NULL) {
        delete street_line_1;
    }
if(street_line_2 != NULL) {
        delete street_line_2;
    }
if(suffix != NULL) {
        delete suffix;
    }
if(title != NULL) {
        delete title;
    }
if(type != NULL) {
        delete type;
    }
if(zip_code != NULL) {
        delete zip_code;
    }
}

SWGProvider*
SWGProvider::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGProvider::fromJsonObject(QJsonObject &pJson) {
    setValue(&accepting_change_of_payor_patients, pJson["accepting_change_of_payor_patients"], "bool", "");
setValue(&accepting_medicaid_patients, pJson["accepting_medicaid_patients"], "bool", "");
setValue(&accepting_medicare_patients, pJson["accepting_medicare_patients"], "bool", "");
setValue(&accepting_private_patients, pJson["accepting_private_patients"], "bool", "");
setValue(&accepting_referral_patients, pJson["accepting_referral_patients"], "bool", "");
setValue(&city, pJson["city"], "QString", "QString");
setValue(&email, pJson["email"], "QString", "QString");
setValue(&gender, pJson["gender"], "QString", "QString");
setValue(&first_name, pJson["first_name"], "QString", "QString");
setValue(&hios_ids, pJson["hios_ids"], "QList", "QString");
setValue(&id, pJson["id"], "qint32", "");
setValue(&last_name, pJson["last_name"], "QString", "QString");
setValue(&latitude, pJson["latitude"], "SWGNumber", "SWGNumber");
setValue(&longitude, pJson["longitude"], "SWGNumber", "SWGNumber");
setValue(&middle_name, pJson["middle_name"], "QString", "QString");
setValue(&network_ids, pJson["network_ids"], "QList", "");
setValue(&personal_phone, pJson["personal_phone"], "QString", "QString");
setValue(&phone, pJson["phone"], "QString", "QString");
setValue(&presentation_name, pJson["presentation_name"], "QString", "QString");
setValue(&specialty, pJson["specialty"], "QString", "QString");
setValue(&state, pJson["state"], "QString", "QString");
setValue(&state_id, pJson["state_id"], "qint32", "");
setValue(&street_line_1, pJson["street_line_1"], "QString", "QString");
setValue(&street_line_2, pJson["street_line_2"], "QString", "QString");
setValue(&suffix, pJson["suffix"], "QString", "QString");
setValue(&title, pJson["title"], "QString", "QString");
setValue(&type, pJson["type"], "QString", "QString");
setValue(&zip_code, pJson["zip_code"], "QString", "QString");
}

QString
SWGProvider::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGProvider::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("accepting_change_of_payor_patients", QJsonValue(accepting_change_of_payor_patients));
obj->insert("accepting_medicaid_patients", QJsonValue(accepting_medicaid_patients));
obj->insert("accepting_medicare_patients", QJsonValue(accepting_medicare_patients));
obj->insert("accepting_private_patients", QJsonValue(accepting_private_patients));
obj->insert("accepting_referral_patients", QJsonValue(accepting_referral_patients));

    
    toJsonValue(QString("city"), city, obj, QString("QString"));
    
        

    
    toJsonValue(QString("email"), email, obj, QString("QString"));
    
        

    
    toJsonValue(QString("gender"), gender, obj, QString("QString"));
    
        

    
    toJsonValue(QString("first_name"), first_name, obj, QString("QString"));
    
        

    
    QList<QString*>* hios_idsList = hios_ids;
    QJsonArray hios_idsJsonArray;
    toJsonArray((QList<void*>*)hios_ids, &hios_idsJsonArray, "hios_ids", "QString");

    obj->insert("hios_ids", hios_idsJsonArray);
    
obj->insert("id", QJsonValue(id));

    
    toJsonValue(QString("last_name"), last_name, obj, QString("QString"));
    
        

    
    toJsonValue(QString("latitude"), latitude, obj, QString("SWGNumber"));
    
        

    
    toJsonValue(QString("longitude"), longitude, obj, QString("SWGNumber"));
    
        

    
    toJsonValue(QString("middle_name"), middle_name, obj, QString("QString"));
    
        
obj->insert("network_ids", QJsonValue(network_ids));

    
    toJsonValue(QString("personal_phone"), personal_phone, obj, QString("QString"));
    
        

    
    toJsonValue(QString("phone"), phone, obj, QString("QString"));
    
        

    
    toJsonValue(QString("presentation_name"), presentation_name, obj, QString("QString"));
    
        

    
    toJsonValue(QString("specialty"), specialty, obj, QString("QString"));
    
        

    
    toJsonValue(QString("state"), state, obj, QString("QString"));
    
        
obj->insert("state_id", QJsonValue(state_id));

    
    toJsonValue(QString("street_line_1"), street_line_1, obj, QString("QString"));
    
        

    
    toJsonValue(QString("street_line_2"), street_line_2, obj, QString("QString"));
    
        

    
    toJsonValue(QString("suffix"), suffix, obj, QString("QString"));
    
        

    
    toJsonValue(QString("title"), title, obj, QString("QString"));
    
        

    
    toJsonValue(QString("type"), type, obj, QString("QString"));
    
        

    
    toJsonValue(QString("zip_code"), zip_code, obj, QString("QString"));
    
        

    return obj;
}

bool
SWGProvider::getAcceptingChangeOfPayorPatients() {
    return accepting_change_of_payor_patients;
}
void
SWGProvider::setAcceptingChangeOfPayorPatients(bool accepting_change_of_payor_patients) {
    this->accepting_change_of_payor_patients = accepting_change_of_payor_patients;
}

bool
SWGProvider::getAcceptingMedicaidPatients() {
    return accepting_medicaid_patients;
}
void
SWGProvider::setAcceptingMedicaidPatients(bool accepting_medicaid_patients) {
    this->accepting_medicaid_patients = accepting_medicaid_patients;
}

bool
SWGProvider::getAcceptingMedicarePatients() {
    return accepting_medicare_patients;
}
void
SWGProvider::setAcceptingMedicarePatients(bool accepting_medicare_patients) {
    this->accepting_medicare_patients = accepting_medicare_patients;
}

bool
SWGProvider::getAcceptingPrivatePatients() {
    return accepting_private_patients;
}
void
SWGProvider::setAcceptingPrivatePatients(bool accepting_private_patients) {
    this->accepting_private_patients = accepting_private_patients;
}

bool
SWGProvider::getAcceptingReferralPatients() {
    return accepting_referral_patients;
}
void
SWGProvider::setAcceptingReferralPatients(bool accepting_referral_patients) {
    this->accepting_referral_patients = accepting_referral_patients;
}

QString*
SWGProvider::getCity() {
    return city;
}
void
SWGProvider::setCity(QString* city) {
    this->city = city;
}

QString*
SWGProvider::getEmail() {
    return email;
}
void
SWGProvider::setEmail(QString* email) {
    this->email = email;
}

QString*
SWGProvider::getGender() {
    return gender;
}
void
SWGProvider::setGender(QString* gender) {
    this->gender = gender;
}

QString*
SWGProvider::getFirstName() {
    return first_name;
}
void
SWGProvider::setFirstName(QString* first_name) {
    this->first_name = first_name;
}

QList<QString*>*
SWGProvider::getHiosIds() {
    return hios_ids;
}
void
SWGProvider::setHiosIds(QList<QString*>* hios_ids) {
    this->hios_ids = hios_ids;
}

qint32
SWGProvider::getId() {
    return id;
}
void
SWGProvider::setId(qint32 id) {
    this->id = id;
}

QString*
SWGProvider::getLastName() {
    return last_name;
}
void
SWGProvider::setLastName(QString* last_name) {
    this->last_name = last_name;
}

SWGNumber*
SWGProvider::getLatitude() {
    return latitude;
}
void
SWGProvider::setLatitude(SWGNumber* latitude) {
    this->latitude = latitude;
}

SWGNumber*
SWGProvider::getLongitude() {
    return longitude;
}
void
SWGProvider::setLongitude(SWGNumber* longitude) {
    this->longitude = longitude;
}

QString*
SWGProvider::getMiddleName() {
    return middle_name;
}
void
SWGProvider::setMiddleName(QString* middle_name) {
    this->middle_name = middle_name;
}

QList<qint32>*
SWGProvider::getNetworkIds() {
    return network_ids;
}
void
SWGProvider::setNetworkIds(QList<qint32>* network_ids) {
    this->network_ids = network_ids;
}

QString*
SWGProvider::getPersonalPhone() {
    return personal_phone;
}
void
SWGProvider::setPersonalPhone(QString* personal_phone) {
    this->personal_phone = personal_phone;
}

QString*
SWGProvider::getPhone() {
    return phone;
}
void
SWGProvider::setPhone(QString* phone) {
    this->phone = phone;
}

QString*
SWGProvider::getPresentationName() {
    return presentation_name;
}
void
SWGProvider::setPresentationName(QString* presentation_name) {
    this->presentation_name = presentation_name;
}

QString*
SWGProvider::getSpecialty() {
    return specialty;
}
void
SWGProvider::setSpecialty(QString* specialty) {
    this->specialty = specialty;
}

QString*
SWGProvider::getState() {
    return state;
}
void
SWGProvider::setState(QString* state) {
    this->state = state;
}

qint32
SWGProvider::getStateId() {
    return state_id;
}
void
SWGProvider::setStateId(qint32 state_id) {
    this->state_id = state_id;
}

QString*
SWGProvider::getStreetLine1() {
    return street_line_1;
}
void
SWGProvider::setStreetLine1(QString* street_line_1) {
    this->street_line_1 = street_line_1;
}

QString*
SWGProvider::getStreetLine2() {
    return street_line_2;
}
void
SWGProvider::setStreetLine2(QString* street_line_2) {
    this->street_line_2 = street_line_2;
}

QString*
SWGProvider::getSuffix() {
    return suffix;
}
void
SWGProvider::setSuffix(QString* suffix) {
    this->suffix = suffix;
}

QString*
SWGProvider::getTitle() {
    return title;
}
void
SWGProvider::setTitle(QString* title) {
    this->title = title;
}

QString*
SWGProvider::getType() {
    return type;
}
void
SWGProvider::setType(QString* type) {
    this->type = type;
}

QString*
SWGProvider::getZipCode() {
    return zip_code;
}
void
SWGProvider::setZipCode(QString* zip_code) {
    this->zip_code = zip_code;
}



} /* namespace Swagger */

