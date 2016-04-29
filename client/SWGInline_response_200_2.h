/*
 * SWGInline_response_200_2.h
 * 
 * 
 */

#ifndef SWGInline_response_200_2_H_
#define SWGInline_response_200_2_H_

#include <QJsonObject>


#include "SWGCounty.h"
#include "SWGZipCode.h"
#include "SWGZipCounty.h"
#include <QList>

#include "SWGObject.h"


namespace Swagger {

class SWGInline_response_200_2: public SWGObject {
public:
    SWGInline_response_200_2();
    SWGInline_response_200_2(QString* json);
    virtual ~SWGInline_response_200_2();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGInline_response_200_2* fromJson(QString &jsonString);

    QList<SWGZipCounty*>* getZipCounties();
    void setZipCounties(QList<SWGZipCounty*>* zip_counties);
QList<SWGCounty*>* getCounties();
    void setCounties(QList<SWGCounty*>* counties);
QList<SWGZipCode*>* getZipCodes();
    void setZipCodes(QList<SWGZipCode*>* zip_codes);

private:
    QList<SWGZipCounty*>* zip_counties;
QList<SWGCounty*>* counties;
QList<SWGZipCode*>* zip_codes;
};

} /* namespace Swagger */

#endif /* SWGInline_response_200_2_H_ */
