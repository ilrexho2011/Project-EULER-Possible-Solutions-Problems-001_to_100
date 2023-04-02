/* XOR decryption

Problem 59 Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.
A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.
For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.
Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.
Your task has been made easy, as the encryption key consists of three lower case characters. Using p059_cipher.txt (right click and 'Save Link/Target As...'), a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.

Pergjigja: 129448  */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  vector< int > cypher;
  int n;
  while ( cin >> n ) {
    cypher.push_back( n );
    cin.ignore();
  }

  int m = *max_element( cypher.begin(), cypher.end() ) + 1;
  vector< int > frec[ 3 ] = {
    vector< int >( m ), vector< int >( m ), vector< int >( m ) };
  for ( int i = 0; i < cypher.size(); i++ )
    frec[ i % 3 ][ cypher[ i ] ]++;

  int pass[ 3 ] = { 0, 0, 0 };
  for ( int i = 0; i <= 2; i++ )
    for ( int j = 0; j < m; j++ )
      if ( frec[ i ][ j ] > pass[ i ] )
        pass[ i ] = j;

  for ( int i = 0; i <= 2; i++ )
     pass[ i ] ^= 32;  // Most common character = space
  
  int sum = 0;
  string text;
  for ( int i = 0; i < cypher.size(); i++ ) {
    char c = static_cast< char >( cypher[ i ] ^ pass[ i % 3 ] );
    sum += c;
    text += c;
  }

  cout << text << endl;
  cout << "Password = " << static_cast< char >( pass[ 0 ] )
       << static_cast< char >( pass[ 1 ] )
       << static_cast< char >( pass[ 2 ] ) << endl;
  cout << "Sum = " << sum << endl;
return 0;
}