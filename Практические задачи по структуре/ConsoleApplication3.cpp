#include <curl/curl.h>
#include <iostream>

// Функция обратного вызова для чтения данных
static size_t read_callback(void* ptr, size_t size, size_t nmemb, void* userp)
{
    const char* data = (const char*)userp;
    size_t length = strlen(data);
    size_t remaining = size * nmemb;

    if (remaining > length) {
        remaining = length;
    }

    memcpy(ptr, data, remaining);
    return remaining;
}

// Функция отправки письма на почту
void send_email(const char* from, const char* to, const char* subject, const char* body)
{
    CURL* curl;
    CURLcode res = CURLE_OK;
    struct curl_slist* recipients = NULL;
    struct curl_slist* headers = NULL;
    char error_buffer[CURL_ERROR_SIZE];

    curl = curl_easy_init();
    if (curl) {
        // Установка параметров
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.yandex.ru:25");
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_USERNAME, "true1909@yandex.ru");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "Nikita-1909");
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from);

        recipients = curl_slist_append(recipients, to);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        headers = curl_slist_append(headers, "Content-Type: text/plain");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_READDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error_buffer);

        // Отправка письма
        curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE, (curl_off_t)strlen(body));
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);
        curl_easy_setopt(curl, CURLOPT_READDATA, body);

        res = curl_easy_perform(curl);

        // Освобождение ресурсов
        curl_slist_free_all(recipients);
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        fprintf(stderr, "Error: %s\n", error_buffer);
    }
}

int main()
{
    const char* from = "true1909@yandex.ru";
    const char* to = "nikitaryzhkov19092001@gmail.com";
    const char* subject = "Test email";
    const char* body = "Hello, world!";

    send_email(from, to, subject, body);

    return 0;
}