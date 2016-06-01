/*
 * SWGProviderShowResponse.h
 * 
 * 
 */

#ifndef SWGProviderShowResponse_H_
#define SWGProviderShowResponse_H_

#include <QJsonObject>


#include "SWGProvider.h"

#include "SWGObject.h"


namespace Swagger {

class SWGProviderShowResponse: public SWGObject {
public:
    SWGProviderShowResponse();
    SWGProviderShowResponse(QString* json);
    virtual ~SWGProviderShowResponse();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGProviderShowResponse* fromJson(QString &jsonString);

    SWGProvider* getProvider();
    void setProvider(SWGProvider* provider);

private:
    SWGProvider* provider;
};

} /* namespace Swagger */

#endif /* SWGProviderShowResponse_H_ */
