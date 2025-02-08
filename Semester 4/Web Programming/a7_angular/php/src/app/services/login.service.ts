import { Injectable } from '@angular/core';
import { HttpClient,HttpHeaders } from '@angular/common/http';
import { Observable,catchError, of } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class LoginService {
  private loginUrl = 'http://localhost/a7_angular/php/login.php';
  username = "";

  httpOptions = {
    headers: new HttpHeaders({
      'Content-Type': 'application/json'
    })
  };

  constructor(private http:HttpClient) { }

  public login(usernameInput: string,passwordInput: string): Observable<any> {
    return this.http.get<any>(this.loginUrl + `?username=${usernameInput} &password=${passwordInput}`)
      .pipe(
        catchError(this.handleError<any>('login', []))
      );

  }

  private handleError<T>(operation = 'operation', result: T = {} as T) {
    return (error: any): Observable<T> => {
      console.log(error);
      return of(result as T);
    }
  }

}
