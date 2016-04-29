/*
 * SWGState.h
 * 
 * 
 */

#ifndef SWGState_H_
#define SWGState_H_

#include <QJsonObject>


#include "QDate.h"
#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGState: public SWGObject {
public:
    SWGState();
    SWGState(QString* json);
    virtual ~SWGState();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGState* fromJson(QString &jsonString);

    qint32 getId();
    void setId(qint32 id);
QString* getName();
    void setName(QString* name);
QString* getCode();
    void setCode(QString* code);
QString* getFipsNumber();
    void setFipsNumber(QString* fips_number);
QDate* getLastDateForIndividual();
    void setLastDateForIndividual(QDate* last_date_for_individual);
QDate* getLastDateForShop();
    void setLastDateForShop(QDate* last_date_for_shop);
bool getLiveForBusiness();
    void setLiveForBusiness(bool live_for_business);
bool getLiveForConsumers();
    void setLiveForConsumers(bool live_for_consumers);

private:
    qint32 id;
QString* name;
QString* code;
QString* fips_number;
QDate* last_date_for_individual;
QDate* last_date_for_shop;
bool live_for_business;
bool live_for_consumers;
};

} /* namespace Swagger */

#endif /* SWGState_H_ */
