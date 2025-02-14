
/* WARNING: Enum "__ns_sect": Some values do not have unique names */

undefined8 Main(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined8 uVar5;
  size_t sVar6;
  hostent *phVar7;
  long lVar8;
  char *pcVar9;
  ulong uVar10;
  byte *pbVar11;
  byte *pbVar12;
  long in_FS_OFFSET;
  byte bVar13;
  int local_1414;
  uint local_13f0;
  int local_13ec;
  ns_msg local_13e8 [2];
  ns_msg local_1398 [2];
  ns_rr local_1348;
  ns_rr local_f28;
  char local_b03 [14];
  undefined6 local_af5;
  undefined2 uStack_aef;
  undefined6 uStack_aed;
  undefined7 local_ae7;
  undefined uStack_ae0;
  undefined7 uStack_adf;
  char userInput  [144];
  undefined local_a48 [256];
  byte local_948 [256];
  u_char local_848 [512];
  u_char local_648 [512];
  char local_448 [1032];
  long local_40;
  
  bVar13 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  setvbuf(stdout,(char *)0x0,2,0);
  __printf_chk(2,"Enter the flag: ");
  pcVar4 = fgets(userInput ,0x81,stdin);
  uVar5 = 1;
  if (pcVar4 == (char *)0x0) goto LAB_001016e1;
  sVar6 = strcspn(userInput ,"\n");
  userInput [sVar6] = '\0';
  __printf_chk(2,"Checking (this may take a while)");
  iVar3 = __res_init();
  if (iVar3 < 0) {
LAB_001017bc:
    fwrite("\nAn unexpected error occurred.\n",1,0x1f,stderr);
  }
  else {
    builtin_strncpy(local_b03,"NS\x11REV\x0eLAC\x0eTF ",0xe);
    FUN_00101910(local_b03);
    phVar7 = gethostbyname(local_b03);
    if (phVar7 != (hostent *)0x0) {
      lVar8 = __res_state();
      iVar3 = phVar7->h_length;
      *(undefined4 *)(lVar8 + 0x10) = 1;
      memcpy((void *)(lVar8 + 0x18),*phVar7->h_addr_list,(long)iVar3);
      local_ae7 = 0x646a7e2768666c;
      uStack_ae0 = 0x3b;
      uStack_adf = 0x2a41500f7d7a74;
      FUN_00101970(&local_ae7);
      iVar3 = res_query(&local_ae7,1,0x10,local_648,0x200);
      if (-1 < iVar3) {
        ns_initparse(local_648,iVar3,local_13e8);
        iVar3 = ns_parserr(local_13e8,ns_s_an,0,&local_1348);
        if ((-1 < iVar3) && (local_1348.type == 0x10)) {
          bVar1 = *local_1348.rdata;
          pbVar11 = local_1348.rdata + 1;
          pbVar12 = local_948;
          for (uVar10 = (ulong)bVar1; uVar10 != 0; uVar10 = uVar10 - 1) {
            *pbVar12 = *pbVar11;
            pbVar11 = pbVar11 + (ulong)bVar13 * -2 + 1;
            pbVar12 = pbVar12 + (ulong)bVar13 * -2 + 1;
          }
          local_948[bVar1] = 0;
          sVar6 = strlen(userInput );
          lVar8 = strtol((char *)local_948,(char **)0x0,10);
          if (sVar6 == (long)(int)lVar8) {
            local_1414 = 0;
LAB_00101540:
            do {
              do {
                local_af5 = 0x6774633f7534;
                uStack_aef = 0x7d3f;
                uStack_aed = 0x1177653f7270;
                FUN_001019e0(&local_af5);
                __snprintf_chk(local_a48,0x100,2,0x100,&local_af5,local_1414);
                iVar3 = res_query(local_a48,1,0x10,local_848,0x200);
                if (iVar3 < 0) {
LAB_0010178d:
                  fwrite("\nAn unexpected error occurred.\n",1,0x1f,stderr);
LAB_001017aa:
                  uVar5 = 0xffffffff;
                  goto LAB_001016e1;
                }
                ns_initparse(local_848,iVar3,local_1398);
                iVar3 = ns_parserr(local_1398,ns_s_an,0,&local_f28);
                if (iVar3 < 0) goto LAB_0010178d;
              } while (local_f28.type != 0x10);
              bVar1 = *local_f28.rdata;
              pbVar11 = local_f28.rdata + 1;
              pcVar4 = local_448;
              if (7 < bVar1) {
                for (uVar10 = (ulong)(bVar1 >> 3); uVar10 != 0; uVar10 = uVar10 - 1) {
                  *(undefined8 *)pcVar4 = *(undefined8 *)pbVar11;
                  pbVar11 = pbVar11 + (ulong)bVar13 * -0x10 + 8;
                  pcVar4 = pcVar4 + (ulong)bVar13 * -0x10 + 8;
                }
              }
              lVar8 = 0;
              if ((bVar1 & 4) != 0) {
                *(undefined4 *)pcVar4 = *(undefined4 *)pbVar11;
                lVar8 = 4;
              }
              if ((bVar1 & 2) != 0) {
                *(undefined2 *)(pcVar4 + lVar8) = *(undefined2 *)(pbVar11 + lVar8);
                lVar8 = lVar8 + 2;
              }
              if ((bVar1 & 1) != 0) {
                pcVar4[lVar8] = pbVar11[lVar8];
              }
              local_448[bVar1] = '\0';
              pcVar4 = strtok(local_448,";");
              pcVar9 = strtok((char *)0x0,";");
              if (pcVar4 == (char *)0x0) {
                if (pcVar9 != (char *)0x0) {
LAB_00101690:
                  iVar3 = __isoc99_sscanf(pcVar9,"%d,%d",&local_13f0,&local_13ec);
                  uVar2 = local_13f0;
                  if ((iVar3 != 2) ||
                     (sVar6 = strlen(userInput ), sVar6 << 3 <= (ulong)(long)(int)uVar2))
                  goto LAB_001016b4;
                  if (((uint)(int)userInput [(int)uVar2 >> 3] >> (~uVar2 & 7) & 1) != 0) {
                    if (local_13ec == 0) goto LAB_0010177f;
                    goto LAB_001016b4;
                  }
                  if (local_13ec != 1) goto LAB_001016b4;
LAB_0010177f:
                  puts("\nIncorrect.");
                  goto LAB_001017aa;
                }
                sleep(1);
                putchar(0x2e);
                goto LAB_00101540;
              }
              lVar8 = strtol(pcVar4,(char **)0x0,10);
              local_1414 = (int)lVar8;
              if (pcVar9 != (char *)0x0) goto LAB_00101690;
LAB_001016b4:
              sleep(1);
              putchar(0x2e);
            } while (local_1414 != -1);
            puts("Correct!");
            uVar5 = 0;
            goto LAB_001016e1;
          }
          puts("\nIncorrect.");
          goto LAB_001017d9;
        }
      }
      goto LAB_001017bc;
    }
    fwrite("\nAn unexpected error occurred. Is the program running in a restricted sandbox?\n",1,
           0x4f,stderr);
  }
LAB_001017d9:
  uVar5 = 0xfffffffe;
LAB_001016e1:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}
