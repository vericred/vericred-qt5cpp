/*
 * SWGZipCountiesResponse.h
 * 
 * 
 */

#ifndef SWGZipCountiesResponse_H_
#define SWGZipCountiesResponse_H_

#include <QJsonObject>


#include "SWGCounty.h"
#include "SWGState.h"
#include "SWGZipCode.h"
#include "SWGZipCounty.h"
#include <QList>

#include "SWGObject.h"


namespace Swagger {

class SWGZipCountiesResponse: public SWGObject {
public:
    SWGZipCountiesResponse();
    SWGZipCountiesResponse(QString* json);
    virtual ~SWGZipCountiesResponse();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGZipCountiesResponse* fromJson(QString &jsonString);

    QList<SWGCounty*>* getCounties();
    void setCounties(QList<SWGCounty*>* counties);
QList<SWGState*>* getStates();
    void setStates(QList<SWGState*>* states);
QList<SWGZipCounty*>* getZipCounties();
    void setZipCounties(QList<SWGZipCounty*>* zip_counties);
QList<SWGZipCode*>* getZipCodes();
    void setZipCodes(QList<SWGZipCode*>* zip_codes);

private:
    QList<SWGCounty*>* counties;
QList<SWGState*>* states;
QList<SWGZipCounty*>* zip_counties;
QList<SWGZipCode*>* zip_codes;
};

} /* namespace Swagger */

#endif /* SWGZipCountiesResponse_H_ */
