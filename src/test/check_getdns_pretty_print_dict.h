#ifndef _check_getdns_pretty_print_dict_h_
#define _check_getdns_pretty_print_dict_h_

    /*
     **************************************************************************
     *                                                                        *
     *  T E S T S  F O R  G E T D N S _ D I C T _ D E S T R O Y               *
     *                                                                        *
     **************************************************************************
    */

    START_TEST (getdns_pretty_print_dict_1)
    {
     /*
      *  this_dict = NULL
      *  expect:  nothing
      */
      struct getdns_dict *some_dict = NULL;

      DICT_DESTROY(some_dict);
    }
    END_TEST

    START_TEST (getdns_pretty_print_dict_2)
    {
     /*
      *  build a complex dict and then print it
      *
      *  dict1-> "int" = 1
      *       -> "bindata" = { 8, "bindata" }
      *       -> "dict" = dict2->"int" = 2
      *                        -> "bindata" = { 8, "bindata" }
      *                        -> "dict" = dict3 -> "int" = 3
      *                                          -> "bindata" = { 8, "bindata" }
      *                                          -> "dict" = dict4 -> "int" = 4
      *                                          -> "list" = list1 0: int = 5
      *                        -> "list" = list2 0: int = 6
      *                                          1: bindata = { 8, "bindata" }
      *                                          2: dict = dict5 -> "bindata" = { 8, "bindata" }
      *                                          3: list = list3 0: bindata = { 8, "bindata" }
      *       -> "list" = list4 0: int = 6
      *                         1: bindata = { 8, "bindata" }
      *                         2: dict6 -> "int" = 8
      *                                  -> "bindata" = { 8, "bindata" }
      *                                  -> "dict" = dict7 -> "int" = 9
      *                                  -> "list" = list5 0: int = 10
      *                         3: list6 0: int = 11
      *                                  1: bindata = { 8, "bindata" }
      *                                  2: dict8 -> "bindata" = { 8, "bindata" }
      *                                  3: list7 0: bindata = { 8, "bindata" }
      *
      *  expect:  nothing
      */
      struct getdns_bindata bindata = { 8, (void *)"bindata" };
      struct getdns_list *list7;
      struct getdns_dict *dict8;
      struct getdns_list *list6;
      struct getdns_list *list5;
      struct getdns_dict *dict7;
      struct getdns_dict *dict6;
      struct getdns_list *list4;
      struct getdns_list *list3;
      struct getdns_dict *dict5;
      struct getdns_list *list2;
      struct getdns_list *list1;
      struct getdns_dict *dict4;
      struct getdns_dict *dict3;
      struct getdns_dict *dict2;
      struct getdns_dict *dict1;

     /*
      *  Build it backwards, with the deepest elements first.
      */

      LIST_CREATE(list7);
      ASSERT_RC(getdns_list_set_bindata(list7, 0, &bindata),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_bindata()");

      DICT_CREATE(dict8);
      ASSERT_RC(getdns_dict_set_bindata(dict8, "bindata", &bindata),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_bindata()");

      LIST_CREATE(list6);
      ASSERT_RC(getdns_list_set_int(list6, 0, 11),
        GETDNS_RETURN_GOOD, "Return code from getdns_list_set_int()");
      ASSERT_RC(getdns_list_set_bindata(list6, 1, &bindata),
        GETDNS_RETURN_GOOD, "Return code from getdns_list_set_bindata()");
      ASSERT_RC(getdns_list_set_dict(list6, 2, dict8),
        GETDNS_RETURN_GOOD, "Return code from getdns_list_set_dict()");
      ASSERT_RC(getdns_list_set_list(list6, 3, list7),
        GETDNS_RETURN_GOOD, "Return code from getdns_list_set_list()");

      LIST_CREATE(list5);
      ASSERT_RC(getdns_list_set_int(list5, 0, 10),
        GETDNS_RETURN_GOOD, "Return code from getdns_list_set_int()");

      DICT_CREATE(dict7);
      ASSERT_RC(getdns_dict_set_int(dict7, "int", 9),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_int()");

      DICT_CREATE(dict6);
      ASSERT_RC(getdns_dict_set_int(dict6, "int", 8),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_int()");
      ASSERT_RC(getdns_dict_set_bindata(dict6, "bindata", &bindata),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_bindata()");
      ASSERT_RC(getdns_dict_set_dict(dict6, "dict", dict7),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_dict()");
      ASSERT_RC(getdns_dict_set_list(dict6, "list", list5),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_list()");

      LIST_CREATE(list4);
      ASSERT_RC(getdns_list_set_int(list4, 0, 7),
        GETDNS_RETURN_GOOD, "Return code from getdns_list_set_int()");
      ASSERT_RC(getdns_list_set_bindata(list4, 1, &bindata),
        GETDNS_RETURN_GOOD, "Return code from getdns_list_set_bindata()");
      ASSERT_RC(getdns_list_set_dict(list4, 2, dict6),
        GETDNS_RETURN_GOOD, "Return code from getdns_list_set_dict()");
      ASSERT_RC(getdns_list_set_list(list4, 3, list5),
        GETDNS_RETURN_GOOD, "Return code from getdns_list_set_list()");

      LIST_CREATE(list3);
      ASSERT_RC(getdns_list_set_bindata(list3, 0, &bindata),
        GETDNS_RETURN_GOOD, "Return code from getdns_list_set_bindata()");

      DICT_CREATE(dict5);
      ASSERT_RC(getdns_dict_set_bindata(dict5, "bindata", &bindata),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_bindata()");

      LIST_CREATE(list2);
      ASSERT_RC(getdns_list_set_int(list2, 0, 6), 
        GETDNS_RETURN_GOOD, "Return code from getdns_list_set_int()");
      ASSERT_RC(getdns_list_set_bindata(list2, 1, &bindata),
        GETDNS_RETURN_GOOD, "Return code from getdns_list_set_bindata()");
      ASSERT_RC(getdns_list_set_dict(list2, 2, dict5),
        GETDNS_RETURN_GOOD, "Return code from getdns_list_set_dict()");
      ASSERT_RC(getdns_list_set_list(list2, 3, list3),
        GETDNS_RETURN_GOOD, "Return code from getdns_list_set_list()");

      LIST_CREATE(list1);
      ASSERT_RC(getdns_list_set_int(list1, 0, 5),
        GETDNS_RETURN_GOOD, "Return code from getdns_list_set_int()");

      DICT_CREATE(dict4);
      ASSERT_RC(getdns_dict_set_int(dict4, "int", 4), 
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_int()");

      DICT_CREATE(dict3);
      ASSERT_RC(getdns_dict_set_int(dict3, "int", 3), 
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_int()");
      ASSERT_RC(getdns_dict_set_bindata(dict3, "bindata", &bindata),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_bindata()");
      ASSERT_RC(getdns_dict_set_dict(dict3, "dict", dict4),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_dict()");
      ASSERT_RC(getdns_dict_set_list(dict3, "list", list1),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_list()");

      DICT_CREATE(dict2);
      ASSERT_RC(getdns_dict_set_int(dict2, "int", 2),  
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_int()");
      ASSERT_RC(getdns_dict_set_bindata(dict2, "bindata", &bindata),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_bindata()");
      ASSERT_RC(getdns_dict_set_dict(dict2, "dict", dict3),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_dict()");
      ASSERT_RC(getdns_dict_set_list(dict2, "list", list2),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_list()");

      DICT_CREATE(dict1);
      ASSERT_RC(getdns_dict_set_int(dict1, "int", 1),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_int()");
      ASSERT_RC(getdns_dict_set_bindata(dict1, "bindata", &bindata),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_bindata()");
      ASSERT_RC(getdns_dict_set_dict(dict1, "dict", dict2),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_dict()");
      ASSERT_RC(getdns_dict_set_list(dict1, "list", list4),
        GETDNS_RETURN_GOOD, "Return code from getdns_dict_set_list()");

      // ck_assert_msg(answer == 100, "Expected retrieved int == 100, got: %d",
      //   answer);


     /*
      *  Destroy all of the sub-dicts and sub-lists
      */
      LIST_DESTROY(list7);
      DICT_DESTROY(dict8);
      LIST_DESTROY(list6);
      LIST_DESTROY(list5);
      DICT_DESTROY(dict7);
      DICT_DESTROY(dict6);
      LIST_DESTROY(list4);
      LIST_DESTROY(list3);
      DICT_DESTROY(dict5);
      LIST_DESTROY(list2);
      LIST_DESTROY(list1);
      DICT_DESTROY(dict4);
      DICT_DESTROY(dict3);
      DICT_DESTROY(dict2);

     /*
      *  And now destroy the mother of all ints, bindata, dicts, and lists
      */
      DICT_DESTROY(dict1);
    }
    END_TEST
    
    Suite *
    getdns_pretty_print_dict_suite (void)
    {
      Suite *s = suite_create ("getdns_pretty_print_dict()");
    
      /* Negative test caseis */
      TCase *tc_neg = tcase_create("Negative");
      tcase_add_test(tc_neg, getdns_pretty_print_dict_1);
      suite_add_tcase(s, tc_neg);
    
      /* Positive test cases */
      TCase *tc_pos = tcase_create("Positive");
      tcase_add_test(tc_pos, getdns_pretty_print_dict_2);
      suite_add_tcase(s, tc_pos);

       return s;
    }

#endif
