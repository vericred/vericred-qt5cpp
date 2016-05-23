/*
 * SWGZipCountyResponse.h
 * 
 * 
 */

#ifndef SWGZipCountyResponse_H_
#define SWGZipCountyResponse_H_

#include <QJsonObject>


#include "SWGCounty.h"
#include "SWGState.h"
#include "SWGZipCode.h"
#include "SWGZipCounty.h"
#include <QList>

#include "SWGObject.h"


namespace Swagger {

class SWGZipCountyResponse: public SWGObject {
public:
    SWGZipCountyResponse();
    SWGZipCountyResponse(QString* json);
    virtual ~SWGZipCountyResponse();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGZipCountyResponse* fromJson(QString &jsonString);

    QList<SWGCounty*>* getCounties();
    void setCounties(QList<SWGCounty*>* counties);
QList<SWGState*>* getStates();
    void setStates(QList<SWGState*>* states);
QList<SWGZipCode*>* getZipCodes();
    void setZipCodes(QList<SWGZipCode*>* zip_codes);
SWGZipCounty* getZipCounty();
    void setZipCounty(SWGZipCounty* zip_county);

private:
    QList<SWGCounty*>* counties;
QList<SWGState*>* states;
QList<SWGZipCode*>* zip_codes;
SWGZipCounty* zip_county;
};

} /* namespace Swagger */

#endif /* SWGZipCountyResponse_H_ */
