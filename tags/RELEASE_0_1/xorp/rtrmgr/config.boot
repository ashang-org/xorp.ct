interfaces {
  interface xl0 {
    description: "control interface"
    vif xl0 {
      address 192.150.187.20 {
        prefix-length: 24
        broadcast: 192.150.187.255
      }
    }
    vif xl1 {
    }
  }
}

/*
protocols {
  ospf {
    router-id: 192.150.187.20
    area 0.0.0.0 {
      stub: false
      interface xl0 {
	hello-interval: 5
      }
    }
  }
}
*/