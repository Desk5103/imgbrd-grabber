#ifndef DOWNLOAD_QUERY_IMAGE_H
#define DOWNLOAD_QUERY_IMAGE_H

#include <QJsonObject>
#include <QMap>
#include <QSettings>
#include <QString>
#include "downloader/download-query.h"


class Image;
class Site;

class DownloadQueryImage : public DownloadQuery
{
	public:
		// Constructors
		DownloadQueryImage() = default;
		explicit DownloadQueryImage(QSettings *settings, const Image &img, Site *site);
		explicit DownloadQueryImage(const Image &img, Site *site, const QString &filename, const QString &path);
		explicit DownloadQueryImage(qulonglong id, const QString &md5, const QString &rating, const QString &tags, const QString &fileUrl, const QString &date, Site *site, const QString &filename, const QString &path);

		// Serialization
		QString toString(const QString &separator) const override;
		void write(QJsonObject &json) const override;
		bool read(const QJsonObject &json, const QMap<QString, Site*> &sites) override;

		// Public members
		QMap<QString, QString> values;

	private:
		void initFromImage(const Image &img);
		void initFromData(qulonglong id, const QString &md5, const QString &rating, const QString &tags, const QString &fileUrl, const QString &date);
};

bool operator==(const DownloadQueryImage &lhs, const DownloadQueryImage &rhs);
bool operator!=(const DownloadQueryImage &lhs, const DownloadQueryImage &rhs);

Q_DECLARE_METATYPE(DownloadQueryImage)

#endif // DOWNLOAD_QUERY_IMAGE_H
