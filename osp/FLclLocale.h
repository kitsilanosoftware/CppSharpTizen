//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FLclLocale.h
 * @brief	This is the header file for the %Locale class.
 *
 * This header file contains the declarations of the %Locale class.
 */
#ifndef _FLCL_LOCALE_H_
#define _FLCL_LOCALE_H_

#include <FBaseObject.h>
#include <FBaseString.h>

namespace Tizen { namespace Locales
{

/**
 * @enum	CalendarType
 *
 * Defines the calendar type.
 *
 * @since		2.0
 */
enum CalendarType
{
	CALENDAR_GREGORIAN,             /**< The calendar type: Gregorian calendar (default) */
	CALENDAR_BUDDHIST,              /**< The calendar type: Buddhist calendar (same as Gregorian except for the year)  */
	CALENDAR_CHINESE,               /**< The calendar type: Traditional Chinese calendar  */
	CALENDAR_COPTIC,                /**< The calendar type: Coptic calendar  */
	CALENDAR_ETHIOPIC_AMETE_ALEM,   /**< The calendar type: Ethiopic calendar, Amete Alem (epoch approx. 5493 B.C.E.)  */
	CALENDAR_ETHIOPIC,              /**< The calendar type: Ethiopic calendar, Amete Mihret (epoch approx. 8 C.E.)  */
	CALENDAR_HEBREW,                /**< The calendar type: TraditionalHebrew calendar  */
	CALENDAR_INDIAN,                /**< The calendar type: Indian calendar  */
	CALENDAR_ISLAMIC,               /**< The calendar type: Astronomical Arabic calendar  */
	CALENDAR_ISLAMIC_CIVIL,         /**< The calendar type: Civil (algorithmic) Arabic calendar  */
	CALENDAR_JAPANESE,              /**< The calendar type: Japanese Imperial calendar (same as Gregorian except for the year, with one era for each Emperor)  */
	CALENDAR_PERSIAN,               /**< The calendar type: Persian calendar  */
	CALENDAR_ROC,                   /**< The calendar type: Republic of China calendar  */
	CALENDAR_TAIWAN,                /**< The calendar type: Taiwan calendar  */
	CALENDAR_ISO8601,               /**< The calendar type: ISO8601 calendar  */
	CALENDAR_COUNT,
};

/**
 * @enum	LanguageCode
 *
 * Defines the ISO 639-2 language code. @n
 * The LanguageCode enumerator represents the ISO 639-2 language codes. @n
 * The specified LanguageCode represents the language code with the locale's ISO-15924 abbreviation script code. 
 *
 * @since		2.0
 */
enum LanguageCode
{
	LANGUAGE_AAR, /**< Afar */
	LANGUAGE_ABK, /**< Abkhazian */
	LANGUAGE_ACE, /**< Achinese */
	LANGUAGE_ACH, /**< Acoli */
	LANGUAGE_ADA, /**< Adangme */
	LANGUAGE_ADY, /**< Adyghe; Adygei */
	LANGUAGE_AFA, /**< Afro-Asiatic languages */
	LANGUAGE_AFH, /**< Afrihili */
	LANGUAGE_AFR, /**< Afrikaans */
	LANGUAGE_AIN, /**< Ainu */
	LANGUAGE_AKA, /**< Akan */
	LANGUAGE_AKK, /**< Akkadian */
	LANGUAGE_SQI, /**< Albanian */
	LANGUAGE_ALE, /**< Aleut */
	LANGUAGE_ALG, /**< Algonquian languages */
	LANGUAGE_ALT, /**< Southern Altai */
	LANGUAGE_AMH, /**< Amharic */
	LANGUAGE_ANG, /**< English, Old (ca.450-1100) */
	LANGUAGE_ANP, /**< Angika */
	LANGUAGE_APA, /**< Apache languages */
	LANGUAGE_ARA, /**< Arabic */
	LANGUAGE_ARC, /**< Official Aramaic (700-300 BCE); Imperial Aramaic (700-300 BCE) */
	LANGUAGE_ARG, /**< Aragonese */
	LANGUAGE_HYE, /**< Armenian */
	LANGUAGE_ARN, /**< Mapudungun; Mapuche */
	LANGUAGE_ARP, /**< Arapaho */
	LANGUAGE_ART, /**< Artificial languages */
	LANGUAGE_ARW, /**< Arawak */
	LANGUAGE_ASM, /**< Assamese */
	LANGUAGE_AST, /**< Asturian; Bable; Leonese; Asturleonese */
	LANGUAGE_ATH, /**< Athapascan languages */
	LANGUAGE_AUS, /**< Australian languages */
	LANGUAGE_AVA, /**< Avaric */
	LANGUAGE_AVE, /**< Avestan */
	LANGUAGE_AWA, /**< Awadhi */
	LANGUAGE_AYM, /**< Aymara */
	LANGUAGE_AZE, /**< Azerbaijani */
	LANGUAGE_AZE_ARAB, /**< Azerbaijani (Arabic) */
	LANGUAGE_AZE_CYRL, /**< Azerbaijani (Cyrillic) */
	LANGUAGE_AZE_LATIN, /**< Azerbaijani (Latin) */
	LANGUAGE_BAD, /**< Banda languages */
	LANGUAGE_BAI, /**< Bamileke languages */
	LANGUAGE_BAK, /**< Bashkir */
	LANGUAGE_BAL, /**< Baluchi */
	LANGUAGE_BAM, /**< Bambara */
	LANGUAGE_BAN, /**< Balinese */
	LANGUAGE_EUS, /**< Basque */
	LANGUAGE_BAS, /**< Basa */
	LANGUAGE_BAT, /**< Baltic languages */
	LANGUAGE_BEJ, /**< Beja; Bedawiyet */
	LANGUAGE_BEL, /**< Belarusian */
	LANGUAGE_BEM, /**< Bemba */
	LANGUAGE_BEN, /**< Bengali */
	LANGUAGE_BER, /**< Berber languages */
	LANGUAGE_BHO, /**< Bhojpuri */
	LANGUAGE_BIH, /**< Bihari */
	LANGUAGE_BIK, /**< Bikol */
	LANGUAGE_BIN, /**< Bini; Edo */
	LANGUAGE_BIS, /**< Bislama */
	LANGUAGE_BLA, /**< Siksika */
	LANGUAGE_BNT, /**< Bantu (Other) */
	LANGUAGE_BOS, /**< Bosnian */
	LANGUAGE_BRA, /**< Braj */
	LANGUAGE_BRE, /**< Breton */
	LANGUAGE_BTK, /**< Batak languages */
	LANGUAGE_BUA, /**< Buriat */
	LANGUAGE_BUG, /**< Buginese */
	LANGUAGE_BUL, /**< Bulgarian */
	LANGUAGE_MYA, /**< Burmese */
	LANGUAGE_BYN, /**< Blin; Bilin */
	LANGUAGE_CAD, /**< Caddo */
	LANGUAGE_CAI, /**< Central American Indian languages */
	LANGUAGE_CAR, /**< Galibi Carib */
	LANGUAGE_CAT, /**< Catalan; Valencian */
	LANGUAGE_CAU, /**< Caucasian languages */
	LANGUAGE_CEB, /**< Cebuano */
	LANGUAGE_CEL, /**< Celtic languages */
	LANGUAGE_CHA, /**< Chamorro */
	LANGUAGE_CHB, /**< Chibcha */
	LANGUAGE_CHE, /**< Chechen */
	LANGUAGE_CHG, /**< Chagatai */
	LANGUAGE_ZHO, /**< Chinese */
	LANGUAGE_ZHO_HANS, /**< Chinese (Simplified)  */
	LANGUAGE_ZHO_HANT, /**< Chinese (Traditional)  */
	LANGUAGE_CHK, /**< Chuukese */
	LANGUAGE_CHM, /**< Mari */
	LANGUAGE_CHN, /**< Chinook jargon */
	LANGUAGE_CHO, /**< Choctaw */
	LANGUAGE_CHP, /**< Chipewyan; Dene Suline */
	LANGUAGE_CHR, /**< Cherokee */
	LANGUAGE_CHU, /**< Church Slavic; Old Slavonic; Church Slavonic; Old Bulgarian; Old Church Slavonic */
	LANGUAGE_CHV, /**< Chuvash */
	LANGUAGE_CHY, /**< Cheyenne */
	LANGUAGE_CMC, /**< Chamic languages */
	LANGUAGE_COP, /**< Coptic */
	LANGUAGE_COR, /**< Cornish */
	LANGUAGE_COS, /**< Corsican */
	LANGUAGE_CPE, /**< Creoles and pidgins, English based */
	LANGUAGE_CPF, /**< Creoles and pidgins, French-based  */
	LANGUAGE_CPP, /**< Creoles and pidgins, Portuguese-based  */
	LANGUAGE_CRE, /**< Cree */
	LANGUAGE_CRH, /**< Crimean Tatar; Crimean Turkish */
	LANGUAGE_CRP, /**< Creoles and pidgins  */
	LANGUAGE_CSB, /**< Kashubian */
	LANGUAGE_CUS, /**< Cushitic languages */
	LANGUAGE_CES, /**< Czech */
	LANGUAGE_DAK, /**< Dakota */
	LANGUAGE_DAN, /**< Danish */
	LANGUAGE_DAR, /**< Dargwa */
	LANGUAGE_DAY, /**< Land Dayak languages */
	LANGUAGE_DEL, /**< Delaware */
	LANGUAGE_DEN, /**< Slave (Athapascan) */
	LANGUAGE_DGR, /**< Dogrib */
	LANGUAGE_DIN, /**< Dinka */
	LANGUAGE_DIV, /**< Divehi; Dhivehi; Maldivian */
	LANGUAGE_DOI, /**< Dogri */
	LANGUAGE_DRA, /**< Dravidian languages */
	LANGUAGE_DSB, /**< Lower Sorbian */
	LANGUAGE_DUA, /**< Duala */
	LANGUAGE_DUM, /**< Dutch, Middle (ca.1050-1350) */
	LANGUAGE_NLD, /**< Dutch; Flemish */
	LANGUAGE_DYU, /**< Dyula */
	LANGUAGE_DZO, /**< Dzongkha */
	LANGUAGE_EFI, /**< Efik */
	LANGUAGE_EGY, /**< Egyptian (Ancient) */
	LANGUAGE_EKA, /**< Ekajuk */
	LANGUAGE_ELX, /**< Elamite */
	LANGUAGE_ENG, /**< English */
	LANGUAGE_ENM, /**< English, Middle (1100-1500) */
	LANGUAGE_EPO, /**< Esperanto */
	LANGUAGE_EST, /**< Estonian */
	LANGUAGE_EWE, /**< Ewe */
	LANGUAGE_EWO, /**< Ewondo */
	LANGUAGE_FAN, /**< Fang */
	LANGUAGE_FAO, /**< Faroese */
	LANGUAGE_FAT, /**< Fanti */
	LANGUAGE_FIJ, /**< Fijian */
	LANGUAGE_FIL, /**< Filipino; Pilipino */
	LANGUAGE_FIN, /**< Finnish */
	LANGUAGE_FIU, /**< Finno-Ugrian languages */
	LANGUAGE_FON, /**< Fon */
	LANGUAGE_FRA, /**< French */
	LANGUAGE_FRM, /**< French, Middle (ca.1400-1600) */
	LANGUAGE_FRO, /**< French, Old (842-ca.1400) */
	LANGUAGE_FRR, /**< Northern Frisian */
	LANGUAGE_FRS, /**< Eastern Frisian */
	LANGUAGE_FRY, /**< Western Frisian */
	LANGUAGE_FUL, /**< Fulah */
	LANGUAGE_FUR, /**< Friulian */
	LANGUAGE_GAA, /**< Ga */
	LANGUAGE_GAY, /**< Gayo */
	LANGUAGE_GBA, /**< Gbaya */
	LANGUAGE_GEM, /**< Germanic languages */
	LANGUAGE_KAT, /**< Georgian */
	LANGUAGE_DEU, /**< German */
	LANGUAGE_GEZ, /**< Geez */
	LANGUAGE_GIL, /**< Gilbertese */
	LANGUAGE_GLA, /**< Gaelic; Scottish Gaelic */
	LANGUAGE_GLE, /**< Irish */
	LANGUAGE_GLG, /**< Galician */
	LANGUAGE_GLV, /**< Manx */
	LANGUAGE_GMH, /**< German, Middle High (ca.1050-1500) */
	LANGUAGE_GOH, /**< German, Old High (ca.750-1050) */
	LANGUAGE_GON, /**< Gondi */
	LANGUAGE_GOR, /**< Gorontalo */
	LANGUAGE_GOT, /**< Gothic */
	LANGUAGE_GRB, /**< Grebo */
	LANGUAGE_GRC, /**< Greek, Ancient (to 1453) */
	LANGUAGE_ELL, /**< Greek, Modern (1453-) */
	LANGUAGE_GRN, /**< Guarani */
	LANGUAGE_GSW, /**< Swiss German; Alemannic; Alsatian */
	LANGUAGE_GUJ, /**< Gujarati */
	LANGUAGE_GWI, /**< Gwich'in */
	LANGUAGE_HAI, /**< Haida */
	LANGUAGE_HAT, /**< Haitian; Haitian Creole */
	LANGUAGE_HAU, /**< Hausa */
	LANGUAGE_HAU_LATIN, /**< Hausa (Latin) */
	LANGUAGE_HAW, /**< Hawaiian */
	LANGUAGE_HEB, /**< Hebrew */
	LANGUAGE_HER, /**< Herero */
	LANGUAGE_HIL, /**< Hiligaynon */
	LANGUAGE_HIM, /**< Himachali */
	LANGUAGE_HIN, /**< Hindi */
	LANGUAGE_HIT, /**< Hittite */
	LANGUAGE_HMN, /**< Hmong */
	LANGUAGE_HMO, /**< Hiri Motu */
	LANGUAGE_HRV, /**< Croatian */
	LANGUAGE_HSB, /**< Upper Sorbian */
	LANGUAGE_HUN, /**< Hungarian */
	LANGUAGE_HUP, /**< Hupa */
	LANGUAGE_IBA, /**< Iban */
	LANGUAGE_IBO, /**< Igbo */
	LANGUAGE_ISL, /**< Icelandic */
	LANGUAGE_IDO, /**< Ido */
	LANGUAGE_III, /**< Sichuan Yi; Nuosu */
	LANGUAGE_IJO, /**< Ijo languages */
	LANGUAGE_IKU, /**< Inuktitut */
	LANGUAGE_ILE, /**< Interlingue; Occidental */
	LANGUAGE_ILO, /**< Iloko */
	LANGUAGE_INA, /**< Interlingua (International Auxiliary Language Association) */
	LANGUAGE_INC, /**< Indic languages */
	LANGUAGE_IND, /**< Indonesian */
	LANGUAGE_INE, /**< Indo-European languages */
	LANGUAGE_INH, /**< Ingush */
	LANGUAGE_IPK, /**< Inupiaq */
	LANGUAGE_IRA, /**< Iranian languages */
	LANGUAGE_IRO, /**< Iroquoian languages */
	LANGUAGE_ITA, /**< Italian */
	LANGUAGE_JAV, /**< Javanese */
	LANGUAGE_JBO, /**< Lojban */
	LANGUAGE_JPN, /**< Japanese */
	LANGUAGE_JPR, /**< Judeo-Persian */
	LANGUAGE_JRB, /**< Judeo-Arabic */
	LANGUAGE_KAA, /**< Kara-Kalpak */
	LANGUAGE_KAB, /**< Kabyle */
	LANGUAGE_KAC, /**< Kachin; Jingpho */
	LANGUAGE_KAL, /**< Kalaallisut; Greenlandic */
	LANGUAGE_KAM, /**< Kamba */
	LANGUAGE_KAN, /**< Kannada */
	LANGUAGE_KAR, /**< Karen languages */
	LANGUAGE_KAS, /**< Kashmiri */
	LANGUAGE_KAU, /**< Kanuri */
	LANGUAGE_KAW, /**< Kawi */
	LANGUAGE_KAZ, /**< Kazakh */
	LANGUAGE_KAZ_CYRL, /**< Kazakh (Cyrillic)  */
	LANGUAGE_KBD, /**< Kabardian */
	LANGUAGE_KHA, /**< Khasi */
	LANGUAGE_KHI, /**< Khoisan languages */
	LANGUAGE_KHM, /**< Central Khmer */
	LANGUAGE_KHO, /**< Khotanese; Sakan */
	LANGUAGE_KIK, /**< Kikuyu; Gikuyu */
	LANGUAGE_KIN, /**< Kinyarwanda */
	LANGUAGE_KIR, /**< Kirghiz; Kyrgyz */
	LANGUAGE_KMB, /**< Kimbundu */
	LANGUAGE_KOK, /**< Konkani */
	LANGUAGE_KOM, /**< Komi */
	LANGUAGE_KON, /**< Kongo */
	LANGUAGE_KOR, /**< Korean */
	LANGUAGE_KOS, /**< Kosraean */
	LANGUAGE_KPE, /**< Kpelle */
	LANGUAGE_KRC, /**< Karachay-Balkar */
	LANGUAGE_KRL, /**< Karelian */
	LANGUAGE_KRO, /**< Kru languages */
	LANGUAGE_KRU, /**< Kurukh */
	LANGUAGE_KUA, /**< Kuanyama; Kwanyama */
	LANGUAGE_KUM, /**< Kumyk */
	LANGUAGE_KUR, /**< Kurdish */
	LANGUAGE_KUT, /**< Kutenai */
	LANGUAGE_LAD, /**< Ladino */
	LANGUAGE_LAH, /**< Lahnda */
	LANGUAGE_LAM, /**< Lamba */
	LANGUAGE_LAO, /**< Lao */
	LANGUAGE_LAT, /**< Latin */
	LANGUAGE_LAV, /**< Latvian */
	LANGUAGE_LEZ, /**< Lezghian */
	LANGUAGE_LIM, /**< Limburgan; Limburger; Limburgish */
	LANGUAGE_LIN, /**< Lingala */
	LANGUAGE_LIT, /**< Lithuanian */
	LANGUAGE_LOL, /**< Mongo */
	LANGUAGE_LOZ, /**< Lozi */
	LANGUAGE_LTZ, /**< Luxembourgish; Letzeburgesch */
	LANGUAGE_LUA, /**< Luba-Lulua */
	LANGUAGE_LUB, /**< Luba-Katanga */
	LANGUAGE_LUG, /**< Ganda */
	LANGUAGE_LUI, /**< Luiseno */
	LANGUAGE_LUN, /**< Lunda */
	LANGUAGE_LUO, /**< Luo (Kenya and Tanzania) */
	LANGUAGE_LUS, /**< Lushai */
	LANGUAGE_MKD, /**< Macedonian */
	LANGUAGE_MAD, /**< Madurese */
	LANGUAGE_MAG, /**< Magahi */
	LANGUAGE_MAH, /**< Marshallese */
	LANGUAGE_MAI, /**< Maithili */
	LANGUAGE_MAK, /**< Makasar */
	LANGUAGE_MAL, /**< Malayalam */
	LANGUAGE_MAN, /**< Mandingo */
	LANGUAGE_MRI, /**< Maori */
	LANGUAGE_MAP, /**< Austronesian languages */
	LANGUAGE_MAR, /**< Marathi */
	LANGUAGE_MAS, /**< Masai */
	LANGUAGE_MSA, /**< Malay */
	LANGUAGE_MDF, /**< Moksha */
	LANGUAGE_MDR, /**< Mandar */
	LANGUAGE_MEN, /**< Mende */
	LANGUAGE_MGA, /**< Irish, Middle (900-1200) */
	LANGUAGE_MIC, /**< Mi'kmaq; Micmac */
	LANGUAGE_MIN, /**< Minangkabau */
	LANGUAGE_MIS, /**< Uncoded languages */
	LANGUAGE_MKH, /**< Mon-Khmer languages */
	LANGUAGE_MLG, /**< Malagasy */
	LANGUAGE_MLT, /**< Maltese */
	LANGUAGE_MNC, /**< Manchu */
	LANGUAGE_MNI, /**< Manipuri */
	LANGUAGE_MNO, /**< Manobo languages */
	LANGUAGE_MOH, /**< Mohawk */
	LANGUAGE_MON, /**< Mongolian */
	LANGUAGE_MOS, /**< Mossi */
	LANGUAGE_MUL, /**< Multiple languages */
	LANGUAGE_MUN, /**< Munda languages */
	LANGUAGE_MUS, /**< Creek */
	LANGUAGE_MWL, /**< Mirandese */
	LANGUAGE_MWR, /**< Marwari */
	LANGUAGE_MYN, /**< Mayan languages */
	LANGUAGE_MYV, /**< Erzya */
	LANGUAGE_NAH, /**< Nahuatl languages */
	LANGUAGE_NAI, /**< North American Indian languages */
	LANGUAGE_NAP, /**< Neapolitan */
	LANGUAGE_NAU, /**< Nauru */
	LANGUAGE_NAV, /**< Navajo; Navaho */
	LANGUAGE_NBL, /**< Ndebele, South; South Ndebele */
	LANGUAGE_NDE, /**< Ndebele, North; North Ndebele */
	LANGUAGE_NDO, /**< Ndonga */
	LANGUAGE_NDS, /**< Low German; Low Saxon; German, Low; Saxon, Low */
	LANGUAGE_NEP, /**< Nepali */
	LANGUAGE_NEW, /**< Nepal Bhasa; Newari */
	LANGUAGE_NIA, /**< Nias */
	LANGUAGE_NIC, /**< Niger-Kordofanian languages */
	LANGUAGE_NIU, /**< Niuean */
	LANGUAGE_NNO, /**< Norwegian Nynorsk; Nynorsk, Norwegian */
	LANGUAGE_NOB, /**< Bokmal, Norwegian; Norwegian Bokmal */
	LANGUAGE_NOG, /**< Nogai */
	LANGUAGE_NON, /**< Norse, Old */
	LANGUAGE_NOR, /**< Norwegian */
	LANGUAGE_NQO, /**< N'Ko */
	LANGUAGE_NSO, /**< Pedi; Sepedi; Northern Sotho */
	LANGUAGE_NUB, /**< Nubian languages */
	LANGUAGE_NWC, /**< Classical Newari; Old Newari; Classical Nepal Bhasa */
	LANGUAGE_NYA, /**< Chichewa; Chewa; Nyanja */
	LANGUAGE_NYM, /**< Nyamwezi */
	LANGUAGE_NYN, /**< Nyankole */
	LANGUAGE_NYO, /**< Nyoro */
	LANGUAGE_NZI, /**< Nzima */
	LANGUAGE_OCI, /**< Occitan (post 1500); Provencal */
	LANGUAGE_OJI, /**< Ojibwa */
	LANGUAGE_ORI, /**< Oriya */
	LANGUAGE_ORM, /**< Oromo */
	LANGUAGE_OSA, /**< Osage */
	LANGUAGE_OSS, /**< Ossetian; Ossetic */
	LANGUAGE_OTA, /**< Turkish, Ottoman (1500-1928) */
	LANGUAGE_OTO, /**< Otomian languages */
	LANGUAGE_PAA, /**< Papuan languages */
	LANGUAGE_PAG, /**< Pangasinan */
	LANGUAGE_PAL, /**< Pahlavi */
	LANGUAGE_PAM, /**< Pampanga; Kapampangan */
	LANGUAGE_PAN, /**< Panjabi; Punjabi */
	LANGUAGE_PAN_ARAB, /**< Panjabi; Punjabi (Arabic)  */
	LANGUAGE_PAN_GURU, /**< Panjabi; Punjabi (Gurmukhi)  */
	LANGUAGE_PAP, /**< Papiamento */
	LANGUAGE_PAU, /**< Palauan */
	LANGUAGE_PEO, /**< Persian, Old (ca.600-400 B.C.) */
	LANGUAGE_FAS, /**< Persian */
	LANGUAGE_PHI, /**< Philippine languages */
	LANGUAGE_PHN, /**< Phoenician */
	LANGUAGE_PLI, /**< Pali */
	LANGUAGE_POL, /**< Polish */
	LANGUAGE_PON, /**< Pohnpeian */
	LANGUAGE_POR, /**< Portuguese */
	LANGUAGE_PRA, /**< Prakrit languages */
	LANGUAGE_PRO, /**< Provencal, Old (to 1500) */
	LANGUAGE_PUS, /**< Pushto; Pashto */
	LANGUAGE_QAA_QTZ, /**< Reserved for local use */
	LANGUAGE_QUE, /**< Quechua */
	LANGUAGE_RAJ, /**< Rajasthani */
	LANGUAGE_RAP, /**< Rapanui */
	LANGUAGE_RAR, /**< Rarotongan; Cook Islands Maori */
	LANGUAGE_ROA, /**< Romance languages */
	LANGUAGE_ROH, /**< Romansh */
	LANGUAGE_ROM, /**< Romany */
	LANGUAGE_RON, /**< Romanian; Moldavian; Moldovan */
	LANGUAGE_RUN, /**< Rundi */
	LANGUAGE_RUP, /**< Aromanian; Arumanian; Macedo-Romanian */
	LANGUAGE_RUS, /**< Russian */
	LANGUAGE_SAD, /**< Sandawe */
	LANGUAGE_SAG, /**< Sango */
	LANGUAGE_SAH, /**< Yakut */
	LANGUAGE_SAI, /**< South American Indian (Other) */
	LANGUAGE_SAL, /**< Salishan languages */
	LANGUAGE_SAM, /**< Samaritan Aramaic */
	LANGUAGE_SAN, /**< Sanskrit */
	LANGUAGE_SAS, /**< Sasak */
	LANGUAGE_SAT, /**< Santali */
	LANGUAGE_SCN, /**< Sicilian */
	LANGUAGE_SCO, /**< Scots */
	LANGUAGE_SEL, /**< Selkup */
	LANGUAGE_SEM, /**< Semitic languages */
	LANGUAGE_SGA, /**< Irish, Old (to 900) */
	LANGUAGE_SGN, /**< Sign Languages */
	LANGUAGE_SHN, /**< Shan */
	LANGUAGE_SID, /**< Sidamo */
	LANGUAGE_SIN, /**< Sinhala; Sinhalese */
	LANGUAGE_SIO, /**< Siouan languages */
	LANGUAGE_SIT, /**< Sino-Tibetan languages */
	LANGUAGE_SLA, /**< Slavic languages */
	LANGUAGE_SLK, /**< Slovak */
	LANGUAGE_SLV, /**< Slovenian */
	LANGUAGE_SMA, /**< Southern Sami */
	LANGUAGE_SME, /**< Northern Sami */
	LANGUAGE_SMI, /**< Sami languages */
	LANGUAGE_SMJ, /**< Lule Sami */
	LANGUAGE_SMN, /**< Inari Sami */
	LANGUAGE_SMO, /**< Samoan */
	LANGUAGE_SMS, /**< Skolt Sami */
	LANGUAGE_SNA, /**< Shona */
	LANGUAGE_SND, /**< Sindhi */
	LANGUAGE_SNK, /**< Soninke */
	LANGUAGE_SOG, /**< Sogdian */
	LANGUAGE_SOM, /**< Somali */
	LANGUAGE_SON, /**< Songhai languages */
	LANGUAGE_SOT, /**< Sotho, Southern */
	LANGUAGE_SPA, /**< Spanish; Castilian */
	LANGUAGE_SRD, /**< Sardinian */
	LANGUAGE_SRN, /**< Sranan Tongo */
	LANGUAGE_SRP, /**< Serbian */
	LANGUAGE_SRP_CYRL, /**< Serbian (Cyrillic)  */
	LANGUAGE_SRP_LATIN, /**< Serbian (Latin)  */
	LANGUAGE_SRR, /**< Serer */
	LANGUAGE_SSA, /**< Nilo-Saharan languages */
	LANGUAGE_SSW, /**< Swati */
	LANGUAGE_SUK, /**< Sukuma */
	LANGUAGE_SUN, /**< Sundanese */
	LANGUAGE_SUS, /**< Susu */
	LANGUAGE_SUX, /**< Sumerian */
	LANGUAGE_SWA, /**< Swahili */
	LANGUAGE_SWE, /**< Swedish */
	LANGUAGE_SYC, /**< Classical Syriac */
	LANGUAGE_SYR, /**< Syriac */
	LANGUAGE_TAH, /**< Tahitian */
	LANGUAGE_TAI, /**< Tai languages */
	LANGUAGE_TAM, /**< Tamil */
	LANGUAGE_TAT, /**< Tatar */
	LANGUAGE_TEL, /**< Telugu */
	LANGUAGE_TEM, /**< Timne */
	LANGUAGE_TER, /**< Tereno */
	LANGUAGE_TET, /**< Tetum */
	LANGUAGE_TGK, /**< Tajik */
	LANGUAGE_TGL, /**< Tagalog */
	LANGUAGE_THA, /**< Thai */
	LANGUAGE_BOD, /**< Tibetan */
	LANGUAGE_TIG, /**< Tigre */
	LANGUAGE_TIR, /**< Tigrinya */
	LANGUAGE_TIV, /**< Tiv */
	LANGUAGE_TKL, /**< Tokelau */
	LANGUAGE_TLH, /**< Klingon; tlhIngan-Hol */
	LANGUAGE_TLI, /**< Tlingit */
	LANGUAGE_TMH, /**< Tamashek */
	LANGUAGE_TOG, /**< Tonga (Nyasa) */
	LANGUAGE_TON, /**< Tonga (Tonga Islands) */
	LANGUAGE_TPI, /**< Tok Pisin */
	LANGUAGE_TSI, /**< Tsimshian */
	LANGUAGE_TSN, /**< Tswana */
	LANGUAGE_TSO, /**< Tsonga */
	LANGUAGE_TUK, /**< Turkmen */
	LANGUAGE_TUK_CYRL, /**< Turkmen (Cyrillic)  */
	LANGUAGE_TUK_LATIN, /**< Turkmen (Latin)  */
	LANGUAGE_TUM, /**< Tumbuka */
	LANGUAGE_TUP, /**< Tupi languages */
	LANGUAGE_TUR, /**< Turkish */
	LANGUAGE_TUT, /**< Altaic languages */
	LANGUAGE_TVL, /**< Tuvalu */
	LANGUAGE_TWI, /**< Twi */
	LANGUAGE_TYV, /**< Tuvinian */
	LANGUAGE_UDM, /**< Udmurt */
	LANGUAGE_UGA, /**< Ugaritic */
	LANGUAGE_UIG, /**< Uighur; Uyghur */
	LANGUAGE_UKR, /**< Ukrainian */
	LANGUAGE_UMB, /**< Umbundu */
	LANGUAGE_UND, /**< Undetermined */
	LANGUAGE_URD, /**< Urdu */
	LANGUAGE_UZB, /**< Uzbek */
	LANGUAGE_UZB_ARAB, /**< Uzbek (Arabic) */
	LANGUAGE_UZB_CYRL, /**< Uzbek (Cyrillic)  */
	LANGUAGE_UZB_LATIN, /**< Uzbek (Latin)  */
	LANGUAGE_VAI, /**< Vai */
	LANGUAGE_VEN, /**< Venda */
	LANGUAGE_VIE, /**< Vietnamese */
	LANGUAGE_VLS, /**< Vlaams; Flemish"  */
	LANGUAGE_VOL, /**< Volapuk */
	LANGUAGE_VOT, /**< Votic */
	LANGUAGE_WAK, /**< Wakashan languages */
	LANGUAGE_WAL, /**< Walamo */
	LANGUAGE_WAR, /**< Waray */
	LANGUAGE_WAS, /**< Washo */
	LANGUAGE_CYM, /**< Welsh */
	LANGUAGE_WEN, /**< Sorbian languages */
	LANGUAGE_WLN, /**< Walloon */
	LANGUAGE_WOL, /**< Wolof */
	LANGUAGE_XAL, /**< Kalmyk; Oirat */
	LANGUAGE_XHO, /**< Xhosa */
	LANGUAGE_YAO, /**< Yao */
	LANGUAGE_YAP, /**< Yapese */
	LANGUAGE_YID, /**< Yiddish */
	LANGUAGE_YOR, /**< Yoruba */
	LANGUAGE_YPK, /**< Yupik languages */
	LANGUAGE_ZAP, /**< Zapotec */
	LANGUAGE_ZBL, /**< Blissymbols; Blissymbolics; Bliss */
	LANGUAGE_ZEN, /**< Zenaga */
	LANGUAGE_ZHA, /**< Zhuang; Chuang */
	LANGUAGE_ZND, /**< Zande languages */
	LANGUAGE_ZUL, /**< Zulu */
	LANGUAGE_ZUN, /**< Zuni */
	LANGUAGE_ZXX, /**< No linguistic content; Not applicable */
	LANGUAGE_ZZA, /**< Zaza; Dimili; Dimli; Kirdki; Kirmanjki; Zazaki */
	LANGUAGE_MAX, // Language max count
	LANGUAGE_INVALID /**< An invalid language code */
}; // LanguageCode


/**
 * @enum	CountryCode
 *
 * Defines the ISO 3166-1 alpha-2 country code. @n
 * The CountryCode enumerator represents the ISO 3166-1 alpha-2 country codes.
 *
 * @since		2.0
 */
enum CountryCode
{
	COUNTRY_AF, /**< AFGHANISTAN  */
	COUNTRY_AX, /**< ALAND ISLANDS */
	COUNTRY_AL, /**< ALBANIA */
	COUNTRY_DZ, /**< ALGERIA */
	COUNTRY_AS, /**< AMERICAN SAMOA */
	COUNTRY_AD, /**< ANDORRA */
	COUNTRY_AO, /**< ANGOLA */
	COUNTRY_AI, /**< ANGUILLA */
	COUNTRY_AQ, /**< ANTARCTICA */
	COUNTRY_AG, /**< ANTIGUA AND BARBUDA */
	COUNTRY_AR, /**< ARGENTINA */
	COUNTRY_AM, /**< ARMENIA */
	COUNTRY_AW, /**< ARUBA */
	COUNTRY_AU, /**< AUSTRALIA */
	COUNTRY_AT, /**< AUSTRIA */
	COUNTRY_AZ, /**< AZERBAIJAN */
	COUNTRY_BS, /**< BAHAMAS */
	COUNTRY_BH, /**< BAHRAIN */
	COUNTRY_BD, /**< BANGLADESH */
	COUNTRY_BB, /**< BARBADOS */
	COUNTRY_BY, /**< BELARUS */
	COUNTRY_BE, /**< BELGIUM */
	COUNTRY_BZ, /**< BELIZE */
	COUNTRY_BJ, /**< BENIN */
	COUNTRY_BM, /**< BERMUDA */
	COUNTRY_BT, /**< BHUTAN */
	COUNTRY_BO, /**< BOLIVIA */
	COUNTRY_BA, /**< BOSNIA AND HERZEGOVINA */
	COUNTRY_BW, /**< BOTSWANA */
	COUNTRY_BV, /**< BOUVET ISLAND */
	COUNTRY_BR, /**< BRAZIL */
	COUNTRY_IO, /**< BRITISH INDIAN OCEAN TERRITORY */
	COUNTRY_BN, /**< BRUNEI DARUSSALAM */
	COUNTRY_BG, /**< BULGARIA */
	COUNTRY_BF, /**< BURKINA FASO */
	COUNTRY_BI, /**< BURUNDI */
	COUNTRY_KH, /**< CAMBODIA */
	COUNTRY_CM, /**< CAMEROON */
	COUNTRY_CA, /**< CANADA */
	COUNTRY_CV, /**< CAPE VERDE */
	COUNTRY_KY, /**< CAYMAN ISLANDS */
	COUNTRY_CF, /**< CENTRAL AFRICAN REPUBLIC */
	COUNTRY_TD, /**< CHAD */
	COUNTRY_CL, /**< CHILE */
	COUNTRY_CN, /**< CHINA */
	COUNTRY_CX, /**< CHRISTMAS ISLAND */
	COUNTRY_CC, /**< COCOS (KEELING) ISLANDS */
	COUNTRY_CO, /**< COLOMBIA */
	COUNTRY_KM, /**< COMOROS */
	COUNTRY_CG, /**< CONGO */
	COUNTRY_CD, /**< CONGO, THE DEMOCRATIC REPUBLIC OF THE */
	COUNTRY_CK, /**< COOK ISLANDS */
	COUNTRY_CR, /**< COSTA RICA */
	COUNTRY_CI, /**< COTE D'IVOIRE */
	COUNTRY_HR, /**< CROATIA */
	COUNTRY_CU, /**< CUBA */
	COUNTRY_CY, /**< CYPRUS */
	COUNTRY_CZ, /**< CZECH REPUBLIC */
	COUNTRY_DK, /**< DENMARK */
	COUNTRY_DJ, /**< DJIBOUTI */
	COUNTRY_DM, /**< DOMINICA */
	COUNTRY_DO, /**< DOMINICAN REPUBLIC */
	COUNTRY_EC, /**< ECUADOR */
	COUNTRY_EG, /**< EGYPT */
	COUNTRY_SV, /**< EL SALVADOR */
	COUNTRY_GQ, /**< EQUATORIAL GUINEA */
	COUNTRY_ER, /**< ERITREA */
	COUNTRY_EE, /**< ESTONIA */
	COUNTRY_ET, /**< ETHIOPIA */
	COUNTRY_FK, /**< FALKLAND ISLANDS (MALVINAS) */
	COUNTRY_FO, /**< FAROE ISLANDS */
	COUNTRY_FJ, /**< FIJI */
	COUNTRY_FI, /**< FINLAND */
	COUNTRY_FR, /**< FRANCE */
	COUNTRY_GF, /**< FRENCH GUIANA */
	COUNTRY_PF, /**< FRENCH POLYNESIA */
	COUNTRY_TF, /**< FRENCH SOUTHERN TERRITORIES */
	COUNTRY_GA, /**< GABON  */
	COUNTRY_GM, /**< GAMBIA */
	COUNTRY_GE, /**< GEORGIA */
	COUNTRY_DE, /**< GERMANY */
	COUNTRY_GH, /**< GHANA */
	COUNTRY_GI, /**< GIBRALTAR */
	COUNTRY_GR, /**< GREECE */
	COUNTRY_GL, /**< GREENLAND */
	COUNTRY_GD, /**< GRENADA */
	COUNTRY_GP, /**< GUADELOUPE */
	COUNTRY_GU, /**< GUAM */
	COUNTRY_GT, /**< GUATEMALA */
	COUNTRY_GN, /**< GUINEA */
	COUNTRY_GW, /**< GUINEA-BISSAU */
	COUNTRY_GY, /**< GUYANA */
	COUNTRY_HT, /**< HAITI */
	COUNTRY_HM, /**< HEARD ISLAND AND MCDONALD ISLANDS */
	COUNTRY_VA, /**< HOLY SEE (VATICAN CITY STATE) */
	COUNTRY_HN, /**< HONDURAS */
	COUNTRY_HK, /**< HONG KONG */
	COUNTRY_HU, /**< HUNGARY */
	COUNTRY_IS, /**< ICELAND */
	COUNTRY_IN, /**< INDIA */
	COUNTRY_ID, /**< INDONESIA */
	COUNTRY_IR, /**< IRAN, ISLAMIC REPUBLIC OF */
	COUNTRY_IQ, /**< IRAQ */
	COUNTRY_IE, /**< IRELAND */
	COUNTRY_IL, /**< ISRAEL */
	COUNTRY_IT, /**< ITALY */
	COUNTRY_JM, /**< JAMAICA */
	COUNTRY_JP, /**< JAPAN */
	COUNTRY_JO, /**< JORDAN */
	COUNTRY_KZ, /**< KAZAKHSTAN */
	COUNTRY_KE, /**< KENYA */
	COUNTRY_KI, /**< KIRIBATI */
	COUNTRY_KP, /**< KOREA, DEMOCRATIC PEOPLE'S REPUBLIC OF */
	COUNTRY_KR, /**< KOREA, REPUBLIC OF */
	COUNTRY_KW, /**< KUWAIT */
	COUNTRY_KG, /**< KYRGYZSTAN */
	COUNTRY_LA, /**< LAO PEOPLE'S DEMOCRATIC REPUBLIC  */
	COUNTRY_LV, /**< LATVIA */
	COUNTRY_LB, /**< LEBANON */
	COUNTRY_LS, /**< LESOTHO */
	COUNTRY_LR, /**< LIBERIA */
	COUNTRY_LY, /**< LIBYAN ARAB JAMAHIRIYA */
	COUNTRY_LI, /**< LIECHTENSTEIN */
	COUNTRY_LT, /**< LITHUANIA */
	COUNTRY_LU, /**< LUXEMBOURG */
	COUNTRY_MO, /**< MACAO */
	COUNTRY_MK, /**< MACEDONIA, THE FORMER YUGOSLAV REPUBLIC OF */
	COUNTRY_MG, /**< MADAGASCAR */
	COUNTRY_MW, /**< MALAWI */
	COUNTRY_MY, /**< MALAYSIA */
	COUNTRY_MV, /**< MALDIVES */
	COUNTRY_ML, /**< MALI */
	COUNTRY_MT, /**< MALTA */
	COUNTRY_MH, /**< MARSHALL ISLANDS */
	COUNTRY_MQ, /**< MARTINIQUE */
	COUNTRY_MR, /**< MAURITANIA */
	COUNTRY_MU, /**< MAURITIUS */
	COUNTRY_YT, /**< MAYOTTE */
	COUNTRY_MX, /**< MEXICO */
	COUNTRY_FM, /**< MICRONESIA, FEDERATED STATES OF */
	COUNTRY_MD, /**< MOLDOVA, REPUBLIC OF */
	COUNTRY_MC, /**< MONACO */
	COUNTRY_MN, /**< MONGOLIA */
	COUNTRY_MS, /**< MONTSERRAT */
	COUNTRY_MA, /**< MOROCCO */
	COUNTRY_MZ, /**< MOZAMBIQUE */
	COUNTRY_MM, /**< MYANMAR */
	COUNTRY_NA, /**< NAMIBIA */
	COUNTRY_NR, /**< NAURU */
	COUNTRY_NP, /**< NEPAL */
	COUNTRY_NL, /**< NETHERLANDS */
	COUNTRY_AN, /**< NETHERLANDS ANTILLES */
	COUNTRY_NC, /**< NEW CALEDONIA */
	COUNTRY_NZ, /**< NEW ZEALAND */
	COUNTRY_NI, /**< NICARAGUA */
	COUNTRY_NE, /**< NIGER */
	COUNTRY_NG, /**< NIGERIA */
	COUNTRY_NU, /**< NIUE */
	COUNTRY_NF, /**< NORFOLK ISLAND */
	COUNTRY_MP, /**< NORTHERN MARIANA ISLANDS */
	COUNTRY_NO, /**< NORWAY */
	COUNTRY_OM, /**< OMAN */
	COUNTRY_PK, /**< PAKISTAN */
	COUNTRY_PW, /**< PALAU */
	COUNTRY_PS, /**< PALESTINIAN TERRITORY, OCCUPIED */
	COUNTRY_PA, /**< PANAMA */
	COUNTRY_PG, /**< PAPUA NEW GUINEA */
	COUNTRY_PY, /**< PARAGUAY */
	COUNTRY_PE, /**< PERU */
	COUNTRY_PH, /**< PHILIPPINES */
	COUNTRY_PN, /**< PITCAIRN */
	COUNTRY_PL, /**< POLAND */
	COUNTRY_PT, /**< PORTUGAL */
	COUNTRY_PR, /**< PUERTO RICO */
	COUNTRY_QA, /**< QATAR */
	COUNTRY_RE, /**< REUNION */
	COUNTRY_RO, /**< ROMANIA */
	COUNTRY_RU, /**< RUSSIAN FEDERATION */
	COUNTRY_RW, /**< RWANDA */
	COUNTRY_SH, /**< SAINT HELENA  */
	COUNTRY_KN, /**< SAINT KITTS AND NEVIS */
	COUNTRY_LC, /**< SAINT LUCIA */
	COUNTRY_PM, /**< SAINT PIERRE AND MIQUELON */
	COUNTRY_VC, /**< SAINT VINCENT AND THE GRENADINES */
	COUNTRY_WS, /**< SAMOA */
	COUNTRY_SM, /**< SAN MARINO */
	COUNTRY_ST, /**< SAO TOME AND PRINCIPE */
	COUNTRY_SA, /**< SAUDI ARABIA */
	COUNTRY_SN, /**< SENEGAL */
	COUNTRY_SC, /**< SEYCHELLES */
	COUNTRY_SL, /**< SIERRA LEONE */
	COUNTRY_SG, /**< SINGAPORE */
	COUNTRY_SK, /**< SLOVAKIA */
	COUNTRY_SI, /**< SLOVENIA */
	COUNTRY_SB, /**< SOLOMON ISLANDS */
	COUNTRY_SO, /**< SOMALIA */
	COUNTRY_ZA, /**< SOUTH AFRICA */
	COUNTRY_GS, /**< SOUTH GEORGIA AND THE SOUTH SANDWICH ISLANDS */
	COUNTRY_ES, /**< SPAIN */
	COUNTRY_LK, /**< SRI LANKA */
	COUNTRY_SD, /**< SUDAN */
	COUNTRY_SR, /**< SURINAME */
	COUNTRY_SJ, /**< SVALBARD AND JAN MAYEN */
	COUNTRY_SZ, /**< SWAZILAND */
	COUNTRY_SE, /**< SWEDEN */
	COUNTRY_CH, /**< SWITZERLAND */
	COUNTRY_SY, /**< SYRIAN ARAB REPUBLIC */
	COUNTRY_TW, /**< TAIWAN, PROVINCE OF CHINA */
	COUNTRY_TJ, /**< TAJIKISTAN */
	COUNTRY_TZ, /**< TANZANIA, UNITED REPUBLIC OF */
	COUNTRY_TH, /**< THAILAND */
	COUNTRY_TL, /**< TIMOR-LESTE */
	COUNTRY_TG, /**< TOGO */
	COUNTRY_TK, /**< TOKELAU */
	COUNTRY_TO, /**< TONGA */
	COUNTRY_TT, /**< TRINIDAD AND TOBAGO */
	COUNTRY_TN, /**< TUNISIA */
	COUNTRY_TR, /**< TURKEY */
	COUNTRY_TM, /**< TURKMENISTAN */
	COUNTRY_TC, /**< TURKS AND CAICOS ISLANDS */
	COUNTRY_TV, /**< TUVALU */
	COUNTRY_UG, /**< UGANDA */
	COUNTRY_UA, /**< UKRAINE */
	COUNTRY_AE, /**< UNITED ARAB EMIRATES */
	COUNTRY_GB, /**< UNITED KINGDOM */
	COUNTRY_US, /**< UNITED STATES */
	COUNTRY_UM, /**< UNITED STATES MINOR OUTLYING ISLANDS */
	COUNTRY_UY, /**< URUGUAY */
	COUNTRY_UZ, /**< UZBEKISTAN */
	COUNTRY_VU, /**< VANUATU */
	COUNTRY_VE, /**< VENEZUELA */
	COUNTRY_VN, /**< VIET NAM */
	COUNTRY_VG, /**< VIRGIN ISLANDS, BRITISH */
	COUNTRY_VI, /**< VIRGIN ISLANDS, U.S. */
	COUNTRY_WF, /**< WALLIS AND FUTUNA */
	COUNTRY_EH, /**< WESTERN SAHARA */
	COUNTRY_YE, /**< YEMEN */
	COUNTRY_ZM, /**< ZAMBIA */
	COUNTRY_ZW, /**< ZIMBABWE */
	COUNTRY_RS, /**< SERBIA */
	COUNTRY_ME, /**< MONTENEGRO */
	COUNTRY_MAX,    //< Country max count
	COUNTRY_INVALID, //< invalid country code
};


/**
 * @class		Locale
 * @brief		This class is for the locale identification.
 *
 * @since		2.0
 *
 * @final	This class is not intended for extension.
 *
 * @remarks	For more information on the example codes for %Locale class, see LocaleManager.
 *
 * The %Locale class represents a specific geographical, political, or cultural region. @n
 * A %Locale object has three attributes:
 * - Language Code
 * - Country Code
 * - Variant Code
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/locales/lang_country_codes.htm">Retrieving Language and Country Codes</a>.
 *
 * @see	LanguageCode
 * @see	CountryCode
 * @see	LocaleManager
 */

class _OSP_EXPORT_ Locale
	: public Tizen::Base::Object
{
public:
	/**
	 * Initializes an instance of %Locale with the values of the specified locale. @n
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since				2.0
	 *
	 * @param[in]			otherLocale			An instance of %Locale
	 */
	Locale(const Locale& otherLocale);

	/**
	 * Initializes an instance of %Locale with the specified language, country, and variant code.
	 *
	 * @since				2.0
	 *
	 * @param[in]			languageCode					The language code
	 * @param[in]			countryCode						The country code
	 * @param[in]			pVariantCodeString				A pointer to the variant code string @n
	 *										It is converted to a uppercase letter if it is written in a lowercase letter.
	 */
	Locale(LanguageCode languageCode, CountryCode countryCode, const Tizen::Base::String* pVariantCodeString = null);

	/**
	 * Assigns the value of the specified instance to the current instance of %Locale. @n
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since				2.0
	 *
	 * @return			A reference to the current instance of %Locale
	 * @param[in]		otherLocale							An instance of %Locale
	 */
	Locale& operator =(const Locale& otherLocale);

	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~Locale(void);

	/**
	 * Compares the current instance of %Locale with the specified instance of %Locale.
	 *
	 * @since				2.0
	 *
	 * @return			@c true if the value of the specified instance is equal to the value of the current instance, @n
	 *					else @c false
	 * @param[in]		otherLocale						An instance of %Locale
	 */
	bool operator ==(const Locale& otherLocale) const;

	/**
	 * Compares the current instance of %Locale with the specified instance of %Locale.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the value of the specified instance is not equal to the value of the current instance, @n
	 *				else @c false
	 * @param[in]	otherLocale		An instance of %Locale
	 */
	bool operator !=(const Locale& otherLocale) const;

	/**
	 *	Converts the operand @c obj to an object of the %Locale type and then compares it with the current instance of %Locale.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the value of the current instance is equal to the value of the specified Tizen::Base::Object, @n
	 *				else @c false
	 * @param[in]	obj		The object to compare with the current instance
	 * @see		Tizen::Base::Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since		2.0
	 *
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the language code (ISO 639-2 code) of the current instance of %Locale.
	 *
	 * @since		2.0
	 *
	 * @return		The language code enum value of the instance
	 */
	LanguageCode GetLanguageCode(void) const;

	/**
	 * Gets the country code (ISO 3166-1 alpha-2 code) or the area code (ISO 3166-1 numeric-3 code) of the current instance of %Locale.
	 *
	 * @since		2.0
	 *
	 * @return		The country code enum value of the instance
	 */
	CountryCode GetCountryCode(void) const;

	/**
	 * Gets the language code (ISO 639-2 code) string of the current instance of %Locale.
	 *
	 * @since		2.0
	 *
	 * @return		The language code
	 */
	Tizen::Base::String GetLanguageCodeString(void) const;

	/**
	 * Gets the country code (ISO 3166-1 alpha-2 code) or the area code (ISO 3166-1 numeric-3 code) string of the current instance of %Locale.
	 *
	 * @since		2.0
	 *
	 * @return		The country code @n
	 *				else the area code if the country code represents Latin America.
	 */
	Tizen::Base::String GetCountryCodeString(void) const;

	/**
	 * Gets the variant code string of the current instance of %Locale.
	 *
	 * @since		2.0
	 *
	 * @return		The variant code string written in a uppercase letter even if it was set to a lowercase letter, @n
	 *				else an empty string if the variant is not specified
	 * @see			SetVariantCodeString()
	 */
	Tizen::Base::String GetVariantCodeString(void) const;


	/**
	 * Gets the string representing the current instance of %Locale. @n
	 * The string consists of the values returned by GetLanguageCodeString(), GetCountryCodeString(), and GetVariantCodeString() assembled into a string.
	 *
	 * @since					2.0
	 *
	 * @return				A concatenated string with the language code string, country code string, and variant string @n
	 *						For example, if the language code is LANGUAGE_ENG, country code is COUNTRY_US, and variant string is empty, @n
	 *						the locale code string is "eng_US".
	 * @see					GetLanguageCodeString()
	 * @see					GetCountryCodeString()
	 * @see					GetVariantCodeString()
	 */
	Tizen::Base::String GetLocaleCodeString(void) const;

	/**
	 * Gets the country name of the current instance of %Locale that is appropriate for display to the user. @n
	 * The name is localized for this locale. For example, if this locale is eng_US, the name is "United States".
	 *
	 * @since				2.0
	 *
	 * @return				An error code
	 * @param[out]			countryName				The country name of the locale
	 * @exception			E_SUCCESS				The method is successful.
	 * @exception			E_UNSUPPORTED_OPERATION	The current @c locale does not have country name entry in the database.
	 */
	result GetCountryName(Tizen::Base::String& countryName) const;

	/**
	 * Gets the country name of the current instance of %Locale that is appropriate for display to the user in the specified %Locale. @n
	 * The country name is localized for the specified locale(@c otherLocale). For example, if
	 * the current instance of %Locale is fra_FR and the @c otherLocale is eng_US, the name is "France";
	 * if the current instance is eng_US and the @c otherLocale is fra_FR, the name returned is "Etats-Unis".
	 *
	 * @since					2.0
	 *
	 * @return					An error code
	 * @param[in]				otherLocale				An instance of %Locale according to which the country name of the specified %Locale is displayed
	 * @param[out]				countryName				The country name of the locale
	 * @exception				E_SUCCESS				The method is successful.
	 * @exception				E_UNSUPPORTED_OPERATION		The specified @c locale is not supported, or the current @c locale does not have country name entry in the database.
	 */
	result GetCountryName(const Locale& otherLocale, Tizen::Base::String& countryName) const;

	/**
	 * Gets the language name of the current instance of %Locale that is appropriate for display to the user. @n
	 * The name is localized for the locale. For example, if this locale is
	 * eng_US, the name is "English".
	 *
	 * @since					2.0
	 *
	 * @return					An error code
	 * @param[out]				languageName		The language name of the locale
	 * @exception				E_SUCCESS			The method is successful.
	 * @exception				E_UNSUPPORTED_OPERATION		The current @c locale does not have country name entry in the database.
	 */
	result GetLanguageName(Tizen::Base::String& languageName) const;

	/**
	 * Gets the language name of the current instance of %Locale that is appropriate for display to the user in the specified %Locale. @n
	 * The name is localized for the specified locale (@c otherLocale). For example, if
	 * the current instance is fra_FR and the @c otherLocale is eng_US, the name is "French";
	 * if the current instance is engUS and the @c otherLocale is fra_FR, the name returned is "anglais".
	 *
	 * @since					2.0
	 *
	 * @return					An error code
	 * @param[in]				otherLocale				An instance of %Locale according to which the language name of the specified %Locale is displayed
	 * @param[out]				languageName			The language name of the locale
	 * @exception				E_SUCCESS				The method is successful.
	 * @exception				E_UNSUPPORTED_OPERATION		The specified @c locale is not supported, or the current @c locale does not have country name entry in the database.
	 */
	result GetLanguageName(const Locale& otherLocale, Tizen::Base::String& languageName) const;

	/**
	 * Sets the variant code with the specified variant code string. @n
	 * The variant code string is converted to a uppercase letter even if it is set to a lowercase letter.
	 *
	 * @since					2.0
	 *
	 * @param[in]				pVariantCode			A pointer to the variant code	
	 */
	void SetVariantCodeString(const Tizen::Base::String* pVariantCode = null);

	/**
	 * Gets the language code equivalent to the specified language code string.
	 *
	 * @since			2.0
	 *
	 * @param[in]		languageCodeString				The language code 
	 * @return		An instance of LanguageCode associated with the @c languageCodeString.
	 */
	static LanguageCode StringToLanguageCode(const Tizen::Base::String& languageCodeString);

	/**
	 * Gets the country code equivalent to the specified country code string.
	 *
	 * @since			2.0
	 *
	 * @param[in]		countryCodeString				The country code
	 * @return              An instance of CountryCode associated with the @c countryCodeString.
	 */
	static CountryCode StringToCountryCode(const Tizen::Base::String& countryCodeString);

	/**
	 * Gets the language code string equivalent to the specified @c languageCode.
	 *
	 * @since			2.0
	 *
	 * @param[in]		languageCode					The language code
	 * @return		The language code string associated with the @c languageCode, @n
	 *				else an empty string if languageCode is invaild.
	 */
	static Tizen::Base::String LanguageCodeToString(LanguageCode languageCode);

	/**
	 * Gets the country code string equivalent to the specified @c countryCode.
	 *
	 * @since			2.0
	 *
	 * @param[in]		countryCode						The country code
	 * @return		The ISO 3166-1 alpha-2 country code string associated with the @c countryCode, @n
	 *				else an empty string if countryCode is invaild. 
	 */
	static Tizen::Base::String CountryCodeToString(CountryCode countryCode);

	/**
	 * Gets the 2-letter language code string equivalent to the specified @c languageCode.
	 *
	 * @since			2.0
	 *
	 * @param[in]		languageCode					The language code
	 * @return		The ISO 639-2 language code string associated with the @c languageCode, @n
	 *                              else an empty string if languageCode is invaild.
	 */
	static Tizen::Base::String LanguageCodeToTwoLetterLanguageCodeString(LanguageCode languageCode);

	/**
	 * Gets the language code equivalent to the specified 2-letter language code string.
	 *
	 * @since			2.0
	 *
	 * @param[in]		languageCodeString				The language code string
	 * @return		An instance of LanguageCode associated with the @c languageCodeString.
	 */
	static LanguageCode TwoLetterLanguageCodeStringToLanguageCode(const Tizen::Base::String& languageCodeString);

	/**
	 * Gets the 3-letter country code string equivalent to the specified @c countryCode.
	 *
	 * @since			2.0
	 *
	 * @param[in]		countryCode						The country code
	 * @return              The ISO 3166-1 alpha-3 country code string associated with the @c countryCode, @n
	 *                              else an empty string if countryCode is invaild 
	 * @see			CountryCodeToString()
	 */
	static Tizen::Base::String CountryCodeToThreeLetterCountryCodeString(CountryCode countryCode);

	/**
	 * Gets the country code equivalent to the specified 3-letter country code string.
	 *
	 * @since			2.0
	 *
	 * @param[in]		countryCodeString				 The country code string
	 * @return		An instance of CountryCode associated with the @c countryCodeString.
	 * @see			StringToCountryCode() 
	 */
	static CountryCode ThreeLetterCountryCodeStringToCountryCode(const Tizen::Base::String& countryCodeString);

private:

	LanguageCode __languageCode;
	CountryCode __countryCode;

	friend class _LocaleImpl;
	class _LocaleImpl* __pLocaleImpl;

}; // Locale

}} // Tizen::Locales

#endif //_FLCL_LOCALE_H_
