// This file was automatically generated by Scheduler_Factory
// before editing the file please consider generating it again
// $Id$

#include "orbsvcs/Scheduler_Factory.h"

static ACE_Scheduler_Factory::POD_RT_Info runtime_infos_1[] = {
{ "Reactor_Task-25000.us", 1, 0, 0, 0, 250000,
   4, 0, 0, 1, 4, 0, 0, 0 },
{ "Reactor_Task-50000.us", 2, 0, 0, 0, 500000,
   4, 0, 0, 1, 3, 0, 0, 0 },
{ "Reactor_Task-100000.us", 3, 0, 0, 0, 1000000,
   4, 0, 0, 1, 2, 0, 0, 0 },
{ "Reactor_Task-200000.us", 4, 0, 0, 0, 2000000,
   4, 0, 0, 1, 1, 0, 0, 0 },
{ "Reactor_Task-1000000.us", 5, 0, 0, 0, 10000000,
   4, 0, 0, 1, 0, 0, 0, 0 },
{ "ACE_ES_Dispatch_Queue-25000.us", 6, 0, 0, 0, 0,
   4, 0, 0, 1, 4, 0, 0, 0 },
{ "ACE_ES_Dispatch_Queue-50000.us", 7, 0, 0, 0, 0,
   4, 0, 0, 1, 3, 0, 0, 0 },
{ "ACE_ES_Dispatch_Queue-100000.us", 8, 0, 0, 0, 0,
   4, 0, 0, 1, 2, 0, 0, 0 },
{ "ACE_ES_Dispatch_Queue-200000.us", 9, 0, 0, 0, 0,
   4, 0, 0, 1, 1, 0, 0, 0 },
{ "ACE_ES_Dispatch_Queue-1000000.us", 10, 0, 0, 0, 0,
   4, 0, 0, 1, 0, 0, 0, 0 },
{ "hp_supplier_00@ECM1", 11, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "hp_supplier_01@ECM1", 12, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "hp_supplier_02@ECM1", 13, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "hp_supplier_03@ECM1", 14, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "hp_supplier_04@ECM1", 15, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "hp_supplier_05@ECM1", 16, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "hp_supplier_06@ECM1", 17, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "hp_supplier_07@ECM1", 18, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "hp_supplier_08@ECM1", 19, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "hp_supplier_09@ECM1", 20, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "lp_supplier_00@ECM1", 21, 20000, 20000, 20000, 10000000,
   4, 0, 20000, 1, 0, 0, 0, 0 },
{ "lp_supplier_01@ECM1", 22, 20000, 20000, 20000, 10000000,
   4, 0, 20000, 1, 0, 0, 0, 0 },
{ "lp_supplier_02@ECM1", 23, 20000, 20000, 20000, 10000000,
   4, 0, 20000, 1, 0, 0, 0, 0 },
{ "lp_supplier_03@ECM1", 24, 20000, 20000, 20000, 10000000,
   4, 0, 20000, 1, 0, 0, 0, 0 },
{ "lp_supplier_04@ECM1", 25, 20000, 20000, 20000, 10000000,
   4, 0, 20000, 1, 0, 0, 0, 0 },
{ "ecg_ECM2@ECM1", 26, 5000, 5000, 5000, 250000,
   4, 0, 5000, 0, 4, 0, 0, 0 },
{ "ecg_ECM1@ECM1", 27, 5000, 5000, 5000, 250000,
   4, 0, 5000, 1, 4, 0, 0, 0 },
{ "hp_consumer_00@ECM1", 28, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_01@ECM1", 29, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_02@ECM1", 30, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_03@ECM1", 31, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_04@ECM1", 32, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_05@ECM1", 33, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_06@ECM1", 34, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_07@ECM1", 35, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_08@ECM1", 36, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_09@ECM1", 37, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_10@ECM1", 38, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_11@ECM1", 39, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_12@ECM1", 40, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_13@ECM1", 41, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_14@ECM1", 42, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_15@ECM1", 43, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_16@ECM1", 44, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_17@ECM1", 45, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_18@ECM1", 46, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_19@ECM1", 47, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_20@ECM1", 48, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_21@ECM1", 49, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_22@ECM1", 50, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_23@ECM1", 51, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "hp_consumer_24@ECM1", 52, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 4, 0, 0, 0 },
{ "lp_consumer_00@ECM1", 53, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 0, 0, 0, 0 },
{ "lp_consumer_01@ECM1", 54, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 0, 0, 0, 0 },
{ "lp_consumer_02@ECM1", 55, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 0, 0, 0, 0 },
{ "lp_consumer_03@ECM1", 56, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 0, 0, 0, 0 },
{ "lp_consumer_04@ECM1", 57, 20000, 20000, 20000, 0,
   4, 0, 20000, 0, 0, 0, 0, 0 },
{ "consumer_hp_supplier_00@ECM1", 58, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_01@ECM1", 59, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_02@ECM1", 60, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_03@ECM1", 61, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_04@ECM1", 62, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_05@ECM1", 63, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_06@ECM1", 64, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_07@ECM1", 65, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_08@ECM1", 66, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_09@ECM1", 67, 20000, 20000, 20000, 250000,
   4, 0, 20000, 1, 4, 0, 0, 0 },
{ "consumer_lp_supplier_00@ECM1", 68, 20000, 20000, 20000, 10000000,
   4, 0, 20000, 1, 0, 0, 0, 0 },
{ "consumer_lp_supplier_01@ECM1", 69, 20000, 20000, 20000, 10000000,
   4, 0, 20000, 1, 0, 0, 0, 0 },
{ "consumer_lp_supplier_02@ECM1", 70, 20000, 20000, 20000, 10000000,
   4, 0, 20000, 1, 0, 0, 0, 0 },
{ "consumer_lp_supplier_03@ECM1", 71, 20000, 20000, 20000, 10000000,
   4, 0, 20000, 1, 0, 0, 0, 0 },
{ "consumer_lp_supplier_04@ECM1", 72, 20000, 20000, 20000, 10000000,
   4, 0, 20000, 1, 0, 0, 0, 0 }
};

static int runtime_infos_1_size = sizeof(runtime_infos_1)/sizeof(runtime_infos_1[0]);

static ACE_Scheduler_Factory::POD_Config_Info runtime_configs_1[] = {
{          0,        59, (RtecScheduler::Dispatching_Type) 0 }
};
static int runtime_configs_1_size = sizeof(runtime_configs_1)/sizeof(runtime_configs_1[0]);

// EOF

