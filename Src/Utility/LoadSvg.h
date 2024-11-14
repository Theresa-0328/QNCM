#pragma once

#include <QSvgRenderer>
#include <QFile>
#include <QDomDocument>

namespace QNCM
{
inline QDomElement LoadSvgDoc(const QString& svgPath, QDomDocument& svgDoc)
{
    QFile file(svgPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "Unable to open file:" << svgPath;
        return {};
    }
    if (!svgDoc.setContent(&file))
    {
        qWarning() << "SVG file parsing failed:" << svgPath;
        return {};
    }
    file.close();
    QDomElement root = svgDoc.documentElement();
    QDomNodeList pathNodes = root.elementsByTagName("path");
    if (pathNodes.isEmpty())
    {
        qWarning() << "Path element not found:" << svgPath;
        return {};
    }
    auto pathElement = pathNodes.at(0).toElement();
    QString currentFill = pathElement.attribute("fill");
    qDebug() << svgPath << "fill:" << currentFill;
    return pathElement;
}
}