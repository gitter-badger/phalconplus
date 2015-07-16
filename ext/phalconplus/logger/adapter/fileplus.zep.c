
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/hash.h"
#include "kernel/file.h"

ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Adapter_FilePlus) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Logger\\Adapter, FilePlus, phalconplus, logger_adapter_fileplus, zephir_get_internal_ce(SS("phalcon\\logger\\adapter\\file") TSRMLS_CC), phalconplus_logger_adapter_fileplus_method_entry, 0);

	zend_declare_property_null(phalconplus_logger_adapter_fileplus_ce, SL("type2Handler"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_logger_adapter_fileplus_ce, SL("type2Ext"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_logger_adapter_fileplus_ce, SL("mode"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_logger_adapter_fileplus_ce, SL("_path"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_logger_adapter_fileplus_ce, SL("_options"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_logger_adapter_fileplus_ce, SL("_fileHandler"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options = NULL;
	zval *filePath_param = NULL, *options_param = NULL, *mode, _1, *_2 = NULL, *_3, *_4 = NULL, *_5, *_6;
	zval *filePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filePath_param, &options_param);

	if (unlikely(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_EMPTY_STRING(filePath);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	if (EG(called_scope) == phalconplus_logger_adapter_fileplus_ce) {
		zephir_init_properties(this_ptr TSRMLS_CC);
	}
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notempty", &_0, 25, filePath);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(mode);
	if (zephir_array_isset_string_fetch(&mode, options, SS("mode"), 0 TSRMLS_CC)) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "r", 0);
		ZEPHIR_INIT_VAR(_2);
		zephir_fast_strpos(_2, mode, &_1, 0 );
		if (ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
			zephir_update_property_this(this_ptr, SL("mode"), mode TSRMLS_CC);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Logger must be opened in append or write mode", "phalconplus/Logger/Adapter/FilePlus.zep", 24);
			return;
		}
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_3);
		ZVAL_STRING(_3, "ab", 1);
		zephir_update_property_this(this_ptr, SL("mode"), _3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "open", NULL, 49, filePath);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_fileHandler"), _4 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_path"), filePath TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_fileHandler"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, -1);
	zephir_update_property_array(this_ptr, SL("type2Handler"), _2, _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, -1);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "", 1);
	zephir_update_property_array(this_ptr, SL("type2Ext"), _5, _6 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, open) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, *handler = NULL, *_0, *_1;
	zval *filePath = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

	if (unlikely(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_EMPTY_STRING(filePath);
	}
	ZEPHIR_INIT_VAR(handler);
	ZVAL_NULL(handler);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mode"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&handler, "fopen", NULL, 50, filePath, _0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(handler)) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "Cannot open log file ", filePath);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 21, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalconplus/Logger/Adapter/FilePlus.zep", 44 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(handler);

}

PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, log) {

	zval *context = NULL;
	int type, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type_param = NULL, *context_param = NULL, *handler, *_0, *_1, *_2, *_3, *_4;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &message_param, &type_param, &context_param);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!type_param) {
		type = 7;
	} else {
		type = zephir_get_intval(type_param);
	}
	if (!context_param) {
	ZEPHIR_INIT_VAR(context);
	array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_OBS_VAR(handler);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("type2Handler"), PH_NOISY_CC);
	if (zephir_array_isset_long_fetch(&handler, _0, type, 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_fileHandler"), handler TSRMLS_CC);
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("type2Handler"), PH_NOISY_CC);
		zephir_array_fetch_long(&_2, _1, -1, PH_NOISY | PH_READONLY, "phalconplus/Logger/Adapter/FilePlus.zep", 56 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_fileHandler"), _2 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_3);
	zephir_time(_3);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, type);
	ZEPHIR_CALL_PARENT(NULL, phalconplus_logger_adapter_fileplus_ce, this_ptr, "loginternal", NULL, 0, message, _4, _3, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, registerExtension) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *types = NULL;
	zval *ext_param = NULL, *types_param = NULL, *filePath, *type = NULL, *fileHandler = NULL, *_1, **_4;
	zval *ext = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ext_param, &types_param);

	if (unlikely(Z_TYPE_P(ext_param) != IS_STRING && Z_TYPE_P(ext_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ext' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(ext_param) == IS_STRING)) {
		zephir_get_strval(ext, ext_param);
	} else {
		ZEPHIR_INIT_VAR(ext);
		ZVAL_EMPTY_STRING(ext);
	}
	zephir_get_arrval(types, types_param);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notempty", &_0, 25, ext);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notempty", &_0, 25, types);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_path"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(filePath);
	ZEPHIR_CONCAT_VV(filePath, _1, ext);
	ZEPHIR_CALL_METHOD(&fileHandler, this_ptr, "open", NULL, 49, filePath);
	zephir_check_call_status();
	zephir_is_iterable(types, &_3, &_2, 0, 0, "phalconplus/Logger/Adapter/FilePlus.zep", 73);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(type, _4);
		zephir_update_property_array(this_ptr, SL("type2Handler"), type, fileHandler TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("type2Ext"), type, ext TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, close) {

	HashTable *_2;
	HashPosition _1;
	zval *handler = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("type2Handler"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalconplus/Logger/Adapter/FilePlus.zep", 81);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(handler, _3);
		zephir_fclose(handler TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, __wakeup) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *type = NULL, *ext = NULL, *handler = NULL, *ext2Handler, *_0, **_3, *_4, *_5 = NULL, *_7;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(ext2Handler);
	array_init(ext2Handler);

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("type2Ext"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalconplus/Logger/Adapter/FilePlus.zep", 95);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(type, _2, _1);
		ZEPHIR_GET_HVALUE(ext, _3);
		ZEPHIR_OBS_NVAR(handler);
		if (zephir_array_isset_string_fetch(&handler, ext2Handler, SS("ext"), 0 TSRMLS_CC)) {
		} else {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_path"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_VV(_5, _4, ext);
			ZEPHIR_CALL_METHOD(&handler, this_ptr, "open", &_6, 49, _5);
			zephir_check_call_status();
			zephir_array_update_zval(&ext2Handler, ext, &handler, PH_COPY | PH_SEPARATE);
		}
		zephir_update_property_array(this_ptr, SL("type2Handler"), type, handler TSRMLS_CC);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("type2Handler"), PH_NOISY_CC);
	zephir_array_fetch_long(&_7, _4, -1, PH_NOISY | PH_READONLY, "phalconplus/Logger/Adapter/FilePlus.zep", 95 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_fileHandler"), _7 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

static void zephir_init_properties(zval *this_ptr TSRMLS_DC) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("type2Ext"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("type2Handler"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

