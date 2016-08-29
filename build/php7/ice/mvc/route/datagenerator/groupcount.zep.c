
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_DataGenerator_GroupCount) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc\\Route\\DataGenerator, GroupCount, ice, mvc_route_datagenerator_groupcount, ice_mvc_route_datagenerator_regex_ce, ice_mvc_route_datagenerator_groupcount_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_GroupCount, getApproxChunkSize) {

	ZEPHIR_INIT_THIS();


	RETURN_LONG(10);

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_GroupCount, processChunk) {

	zval _11$$3;
	zend_string *_2;
	zend_ulong _1;
	int ZEPHIR_LAST_CALL_STATUS, repeat = 0, i = 0;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	zval *regexToRoutesMap, regexToRoutesMap_sub, routeMap, regex, route, regexes, numGroups, numVariables, *_0, _13, _14, _3$$3, _4$$3, _6$$3, _7$$3, _8$$3, _10$$3, _12$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&regexToRoutesMap_sub);
	ZVAL_UNDEF(&routeMap);
	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&regexes);
	ZVAL_UNDEF(&numGroups);
	ZVAL_UNDEF(&numVariables);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_11$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &regexToRoutesMap);



	ZEPHIR_INIT_VAR(&routeMap);
	array_init(&routeMap);
	ZEPHIR_INIT_VAR(&regexes);
	array_init(&regexes);
	ZEPHIR_INIT_VAR(&numGroups);
	ZVAL_LONG(&numGroups, 0);
	zephir_is_iterable(regexToRoutesMap, 0, "ice/mvc/route/datagenerator/groupcount.zep", 33);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(regexToRoutesMap), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&regex);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&regex, _2);
		} else {
			ZVAL_LONG(&regex, _1);
		}
		ZEPHIR_INIT_NVAR(&route);
		ZVAL_COPY(&route, _0);
		zephir_read_property(&_3$$3, &route, SL("variables"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&numVariables);
		ZVAL_LONG(&numVariables, zephir_fast_count_int(&_3$$3 TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&_4$$3, "max", &_5, 31, &numGroups, &numVariables);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&numGroups, &_4$$3);
		ZEPHIR_INIT_LNVAR(_6$$3);
		zephir_sub_function(&_6$$3, &numGroups, &numVariables);
		repeat = zephir_get_numberval(&_6$$3);
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "()");
		ZVAL_LONG(&_8$$3, repeat);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "str_repeat", &_9, 67, &_7$$3, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_10$$3);
		ZEPHIR_CONCAT_VV(&_10$$3, &regex, &_4$$3);
		zephir_array_append(&regexes, &_10$$3, PH_SEPARATE, "ice/mvc/route/datagenerator/groupcount.zep", 27);
		i = (zephir_get_numberval(&numGroups) + 1);
		ZEPHIR_INIT_NVAR(&_11$$3);
		zephir_create_array(&_11$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&_12$$3);
		zephir_read_property(&_12$$3, &route, SL("handler"), PH_NOISY_CC);
		zephir_array_fast_append(&_11$$3, &_12$$3);
		ZEPHIR_OBS_NVAR(&_12$$3);
		zephir_read_property(&_12$$3, &route, SL("variables"), PH_NOISY_CC);
		zephir_array_fast_append(&_11$$3, &_12$$3);
		zephir_array_update_long(&routeMap, i, &_11$$3, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		ZEPHIR_SEPARATE(&numGroups);
		zephir_increment(&numGroups);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&regex);
	ZEPHIR_INIT_VAR(&_13);
	zephir_fast_join_str(&_13, SL("|"), &regexes TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&regex);
	ZEPHIR_CONCAT_SVS(&regex, "~^(?|", &_13, ")$~");
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_14, "utf8_encode", NULL, 118, &regex);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("regex"), &_14, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("routeMap"), &routeMap, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

