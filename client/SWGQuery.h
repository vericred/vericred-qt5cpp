/*
 * SWGQuery.h
 * 
 * 
 */

#ifndef SWGQuery_H_
#define SWGQuery_H_

#include <QJsonObject>


#include "QDate.h"
#include "SWGApplicant.h"
#include <QList>
#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGQuery: public SWGObject {
public:
    SWGQuery();
    SWGQuery(QString* json);
    virtual ~SWGQuery();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGQuery* fromJson(QString &jsonString);

    QList<SWGApplicant*>* getApplicants();
    void setApplicants(QList<SWGApplicant*>* applicants);
QDate* getEnrollmentDate();
    void setEnrollmentDate(QDate* enrollment_date);
QString* getFipsCode();
    void setFipsCode(QString* fips_code);
QString* getHouseholdIncome();
    void setHouseholdIncome(QString* household_income);
QString* getHouseholdSize();
    void setHouseholdSize(QString* household_size);
QString* getMarket();
    void setMarket(QString* market);
QList<QString*>* getProviders();
    void setProviders(QList<QString*>* providers);
QString* getZipCode();
    void setZipCode(QString* zip_code);

private:
    QList<SWGApplicant*>* applicants;
QDate* enrollment_date;
QString* fips_code;
QString* household_income;
QString* household_size;
QString* market;
QList<QString*>* providers;
QString* zip_code;
};

} /* namespace Swagger */

#endif /* SWGQuery_H_ */
