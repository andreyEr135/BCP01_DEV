cmd_net/netfilter/nf_nat.o := aarch64-poky-linux-ld -EL  -maarch64linux   -r -o net/netfilter/nf_nat.o net/netfilter/nf_nat_core.o net/netfilter/nf_nat_proto_unknown.o net/netfilter/nf_nat_proto_common.o net/netfilter/nf_nat_proto_udp.o net/netfilter/nf_nat_proto_tcp.o net/netfilter/nf_nat_helper.o net/netfilter/nf_nat_proto_dccp.o net/netfilter/nf_nat_proto_sctp.o 
