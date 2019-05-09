#include "Helpers.h"

/**
 * Borrowed from spacehuhn
 * https://github.com/spacehuhn/esp8266_deauther/blob/master/esp8266_deauther/functions.h
 */

bool getBit(uint8_t b, uint8_t n) {
        return (b >> n) % 2 != 0;
}

uint8_t utf8(uint8_t c) {
        if (!getBit(c, 7)) return 1;

        if (getBit(c, 7) && getBit(c, 6) && !getBit(c, 5)) return 2;

        if (getBit(c, 7) && getBit(c, 6) && getBit(c, 5) && !getBit(c, 4)) return 3;

        if (getBit(c, 7) && getBit(c, 6) && getBit(c, 5) && getBit(c, 4) && !getBit(c, 3)) return 4;

        return 0;
}

bool utf8Part(uint8_t c) {
        return getBit(c, 7) && !getBit(c, 6);
}


String fixUtf8(String str) {
        int size = str.length();

        String    result = String();
        char        c;
        uint8_t len;
        bool        ok;

        for (int i = 0; i < size; i++) {
                c     = str.charAt(i);             // get character
                len = utf8(c);                         // get utf8 char len

                if (len <= 1) {
                        result += c;                     // when 1 byte char, add it :)
                }
                else if (i + len > size) { // when char bigger than remaining string, end loop
                        i = size + 1;
                }
                else {
                        ok = true;

                        for (int j = 1; j < len && ok; j++) {
                                ok = utf8Part(str.charAt(i + j));     // if following char is compliant or not
                        }

                        if (ok) result += c;                                        // everything is ok, add char and continue
                        else {                                                                    // utf8 char is broken
                                for (int j = 1; j < len; j++) {         // go through the next bytes
                                        c = str.charAt(i + j);

                                        if (utf8(c) == 1) result += c;    // when byte is ascii, add it :)
                                }
                                i += len - 1;                                             // skip utf8 char because we already managed it
                        }
                }
        }
        return result;
}

String replaceUtf8(String str, String r) {
        str = fixUtf8(str); // fix it in case a utf char is broken
        int size = str.length();

        String    result = String();
        char        c;
        uint8_t len;

        for (int i = 0; i < size; i++) {
                c     = str.charAt(i);                // get character
                len = utf8(c);                            // get utf8 char len

                if (len <= 1) result += c;    // when 1 byte char, add it :)
                else {
                        result += r;
                        i            += len - 1;            // skip other chars
                }
        }

        return result;
}
