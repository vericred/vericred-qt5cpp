/*
 * SWGRequestPlanFind.h
 * 
 * 
 */

#ifndef SWGRequestPlanFind_H_
#define SWGRequestPlanFind_H_

#include <QJsonObject>


#include "SWGDrugPackage.h"
#include "SWGRequestPlanFindApplicant.h"
#include "SWGRequestPlanFindProvider.h"
#include <QList>
#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGRequestPlanFind: public SWGObject {
public:
    SWGRequestPlanFind();
    SWGRequestPlanFind(QString* json);
    virtual ~SWGRequestPlanFind();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGRequestPlanFind* fromJson(QString &jsonString);

    QList<SWGRequestPlanFindApplicant*>* getApplicants();
    void setApplicants(QList<SWGRequestPlanFindApplicant*>* applicants);
QString* getEnrollmentDate();
    void setEnrollmentDate(QString* enrollment_date);
QList<SWGDrugPackage*>* getDrugPackages();
    void setDrugPackages(QList<SWGDrugPackage*>* drug_packages);
QString* getFipsCode();
    void setFipsCode(QString* fips_code);
qint32 getHouseholdIncome();
    void setHouseholdIncome(qint32 household_income);
qint32 getHouseholdSize();
    void setHouseholdSize(qint32 household_size);
QString* getMarket();
    void setMarket(QString* market);
QList<SWGRequestPlanFindProvider*>* getProviders();
    void setProviders(QList<SWGRequestPlanFindProvider*>* providers);
QString* getZipCode();
    void setZipCode(QString* zip_code);

private:
    QList<SWGRequestPlanFindApplicant*>* applicants;
QString* enrollment_date;
QList<SWGDrugPackage*>* drug_packages;
QString* fips_code;
qint32 household_income;
qint32 household_size;
QString* market;
QList<SWGRequestPlanFindProvider*>* providers;
QString* zip_code;
};

} /* namespace Swagger */

#endif /* SWGRequestPlanFind_H_ */
