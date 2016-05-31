/*
 * SWGProvider.h
 * 
 * 
 */

#ifndef SWGProvider_H_
#define SWGProvider_H_

#include <QJsonObject>


#include "SWGNumber.h"
#include <QList>
#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGProvider: public SWGObject {
public:
    SWGProvider();
    SWGProvider(QString* json);
    virtual ~SWGProvider();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGProvider* fromJson(QString &jsonString);

    bool getAcceptingChangeOfPayorPatients();
    void setAcceptingChangeOfPayorPatients(bool accepting_change_of_payor_patients);
bool getAcceptingMedicaidPatients();
    void setAcceptingMedicaidPatients(bool accepting_medicaid_patients);
bool getAcceptingMedicarePatients();
    void setAcceptingMedicarePatients(bool accepting_medicare_patients);
bool getAcceptingPrivatePatients();
    void setAcceptingPrivatePatients(bool accepting_private_patients);
bool getAcceptingReferralPatients();
    void setAcceptingReferralPatients(bool accepting_referral_patients);
QString* getCity();
    void setCity(QString* city);
QString* getEmail();
    void setEmail(QString* email);
QString* getGender();
    void setGender(QString* gender);
QString* getFirstName();
    void setFirstName(QString* first_name);
QList<QString*>* getHiosIds();
    void setHiosIds(QList<QString*>* hios_ids);
qint32 getId();
    void setId(qint32 id);
QString* getLastName();
    void setLastName(QString* last_name);
SWGNumber* getLatitude();
    void setLatitude(SWGNumber* latitude);
SWGNumber* getLongitude();
    void setLongitude(SWGNumber* longitude);
QString* getMiddleName();
    void setMiddleName(QString* middle_name);
QList<qint32>* getNetworkIds();
    void setNetworkIds(QList<qint32>* network_ids);
QString* getPersonalPhone();
    void setPersonalPhone(QString* personal_phone);
QString* getPhone();
    void setPhone(QString* phone);
QString* getPresentationName();
    void setPresentationName(QString* presentation_name);
QString* getSpecialty();
    void setSpecialty(QString* specialty);
QString* getState();
    void setState(QString* state);
qint32 getStateId();
    void setStateId(qint32 state_id);
QString* getStreetLine1();
    void setStreetLine1(QString* street_line_1);
QString* getStreetLine2();
    void setStreetLine2(QString* street_line_2);
QString* getSuffix();
    void setSuffix(QString* suffix);
QString* getTitle();
    void setTitle(QString* title);
QString* getType();
    void setType(QString* type);
QString* getZipCode();
    void setZipCode(QString* zip_code);

private:
    bool accepting_change_of_payor_patients;
bool accepting_medicaid_patients;
bool accepting_medicare_patients;
bool accepting_private_patients;
bool accepting_referral_patients;
QString* city;
QString* email;
QString* gender;
QString* first_name;
QList<QString*>* hios_ids;
qint32 id;
QString* last_name;
SWGNumber* latitude;
SWGNumber* longitude;
QString* middle_name;
QList<qint32>* network_ids;
QString* personal_phone;
QString* phone;
QString* presentation_name;
QString* specialty;
QString* state;
qint32 state_id;
QString* street_line_1;
QString* street_line_2;
QString* suffix;
QString* title;
QString* type;
QString* zip_code;
};

} /* namespace Swagger */

#endif /* SWGProvider_H_ */
