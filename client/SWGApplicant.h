/*
 * SWGApplicant.h
 * 
 * 
 */

#ifndef SWGApplicant_H_
#define SWGApplicant_H_

#include <QJsonObject>


#include "QDate.h"
#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGApplicant: public SWGObject {
public:
    SWGApplicant();
    SWGApplicant(QString* json);
    virtual ~SWGApplicant();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGApplicant* fromJson(QString &jsonString);

    qint32 getId();
    void setId(qint32 id);
QDate* getDob();
    void setDob(QDate* dob);
QString* getMemberId();
    void setMemberId(QString* member_id);
QString* getName();
    void setName(QString* name);
QString* getRelationship();
    void setRelationship(QString* relationship);
bool getSmoker();
    void setSmoker(bool smoker);
QString* getSsn();
    void setSsn(QString* ssn);

private:
    qint32 id;
QDate* dob;
QString* member_id;
QString* name;
QString* relationship;
bool smoker;
QString* ssn;
};

} /* namespace Swagger */

#endif /* SWGApplicant_H_ */
