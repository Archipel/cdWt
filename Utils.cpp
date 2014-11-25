#include <Wt/Utils>
#include <Wt/WString>
#include <cstring>

using namespace std;

namespace Wt {
  namespace Utils {
#if 0 // see header
    enum HtmlEncodingFlag {EncodeNewLines = 0x1};
#endif

    /**
     * Computes an MD5 Hash. This utility function computes an MD5 hash, and returns the raw (binary) hash value.
     * The returned pointer is newly allocated (must be release by free().
     */
    const char* md5(const char* data){
      return strdup(md5(string(data)).c_str());
    }

    /**
     * Computes an SHA-1 Hash. This utility function computes an SHA-1 hash, and returns the raw (binary) hash value.
     * The returned pointer is newly allocated (must be release by free().
     */
    const char* sha1(const char* data){
      return strdup(sha1(string(data)).c_str());
    }

    /**
     * Performs Base64-encoding of data.
     *
     * This utility function implements a Base64 encoding (RFC 2045) of the data.
     *
     * When the crlf argument is true, a CRLF character will be added
     * after each sequence of 76 characters.
     *
     * The returned pointer is newly allocated (must be release by free().
     */
    const char* base64Encode(const char* data, bool crlf = true){
      return strdup(base64Encode(string(data), crlf).c_str());
    }

    /** Performs Base64-decoding of data.
     *
     * This utility function implements a Base64 decoding (RFC 2045) of
     * the \p data. Illegal characters are discarded and skipped.
     *
     * The returned pointer is newly allocated (must be release by free().
     */
    const char* base64Decode(const char* data){
      return strdup(&base64Decode(string(data))[0]);
    }

    /** Performs Hex-decoding of data.
     *
     * A hex-encoding outputs the value of every byte as as two-digit hexadecimal number.
     *
     * The returned pointer is newly allocated (must be release by free().
     */
    const char* hexEncode(const char* data){
      return strdup(hexEncode(string(data)).c_str());
    }

    /** Performs Hex-decoding of data.
     *
     * Illegal characters are discarded and skipped.
     *
     * The returned pointer is newly allocated (must be release by free().
     */
    const char* hexDecode(const char* data){
      return strdup(hexDecode(string(data)).c_str());
    }

    /** Performs HTML encoding of text.
     *
     * This utility function escapes characters so that the text can
     * be embodied verbatim in a HTML text block.
     *
     * The returned pointer is newly allocated (must be release by free().
     */
    const char* htmlEncode(const char* text, int flags = 0){
      return strdup(htmlEncode(string(text), *(WFlags<HtmlEncodingFlag>*)(&flags)).c_str());
    }

    /** Performs Url encoding (aka percentage encoding).
     *
     * This utility function percent encodes a \p text so that it can be
     * embodied verbatim in a URL (e.g. as a fragment).
     *
     * \note To url encode a unicode string, the de-facto standard
     * practice is to encode a UTF-8 encoded string.
     *
     * The returned pointer is newly allocated (must be release by free().
     */
    const char* urlEncode(const char* text){
      return strdup(urlEncode(string(text)).c_str());
    }

    /** Performs Url decoding.
     *
     * This utility function percent encodes a \p text so that it can be
     * embodied verbatim in a URL (e.g. as a fragment).
     *
     * \note To url decode a unicode string, the de-facto standard
     * practice is to interpret the string as a UTF-8 encoded string.
     *
     * The returned pointer is newly allocated (must be release by free().
     */
    const char* urlDecode(const char* text){
      return strdup(urlDecode(string(text)).c_str());
    }

    /*! \brief Remove tags/attributes from text that are not passive.
     *
     * This removes tags and attributes from XHTML-formatted text that do
     * not simply display something but may trigger scripting, and could
     * have been injected by a malicious user for Cross-Site Scripting
     * (XSS).
     *
     * This method is used by the library to sanitize XHTML-formatted text
     * set in WText, but it may also be useful outside the library to
     * sanitize user content when directly using JavaScript.
     *
     * Modifies the \p text if needed. When the text is not proper XML,
     * returns \c false.
     */
    const bool removeScript(const char* text){
      WString wtext(text);
      return removeScript(wtext);
    }

    /*! \brief Guess the image mime type from an image.
     *
     * This function examines the header of an image and tries to identify
     * the image type.
     *
     * At the moment, it recognizes and returns as mime type :
     * - image/png
     * - image/jpeg
     * - image/gif
     * - image/bmp
     *
     * The header should contain (at least) the 25 first bytes of the image data.
     *
     * If no mime-type could be derived, an empty string is returned.
     *
     * The returned pointer is newly allocated (must be release by free().
     */
    const char* guessImageMimeTypeData(const char* header){
      vector<unsigned char> vec;
      for(const char* c = header; *c; c++){
        vec.push_back((unsigned char)*c);
      }
      return strdup(guessImageMimeTypeData(vec).c_str());
    }

    /*! \brief Guess the image mime type from an image.
     *
     * This function opens the image \p file, reads the first 25 bytes and calls
     * guessImageMimeTypeData() to infer the mime type.
     */
    const char* guessImageMimeType(const char* text){
      return strdup(guessImageMimeType(string(text)).c_str());
    }
  }
}
