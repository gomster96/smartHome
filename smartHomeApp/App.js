import React, { Component } from 'react';
import { StyleSheet, Text, View } from 'react-native';
import { render } from 'react-dom';

const net = require('net');
const client = net.createConnection(4000, "192.168.43.212" , ()=>{
  client.write("on LED 1");
  client.write('get_data');
  })


// client.connect(4000, "192.168.43.212" , ()=>{
// client.write("on LED 1");
// client.write('get_data');
// })



// client.on('error', function(error) {
//   console.log(error)
// });

// client.on('data', function(data) {
//   console.log('message was received', data)
// });

export default class App extends Component{
    render()
    {      

      return (
        <View style={styles.container}>
          <Text>Open up App.js to start working on your app!</Text>
        </View>
      );
    }
    
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});
