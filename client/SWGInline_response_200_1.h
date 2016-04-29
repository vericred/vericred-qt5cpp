/*
 * SWGInline_response_200_1.h
 * 
 * 
 */

#ifndef SWGInline_response_200_1_H_
#define SWGInline_response_200_1_H_

#include <QJsonObject>


#include "SWGProvider.h"

#include "SWGObject.h"


namespace Swagger {

class SWGInline_response_200_1: public SWGObject {
public:
    SWGInline_response_200_1();
    SWGInline_response_200_1(QString* json);
    virtual ~SWGInline_response_200_1();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGInline_response_200_1* fromJson(QString &jsonString);

    SWGProvider* getProvider();
    void setProvider(SWGProvider* provider);

private:
    SWGProvider* provider;
};

} /* namespace Swagger */

#endif /* SWGInline_response_200_1_H_ */
