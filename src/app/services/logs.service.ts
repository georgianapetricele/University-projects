import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { catchError, Observable, of } from 'rxjs';
import { Log } from '../model/log';

@Injectable({
  providedIn: 'root'
})
export class LogsService {
  private getAllLogsURL = 'http://localhost/a7_angular/php/getAllLogs.php';
  private getAllLogsUserURL = 'http://localhost/a7_angular/php/getAllLogsForUser.php';
  private getLogsPaginatedURL = 'http://localhost/a7_angular/php/getAllLogsPaginated.php';
  private getLogsPaginatedForUserURL = 'http://localhost/a7_angular/php/getAllLogsPaginatedForUser.php';
  private addLogURL = 'http://localhost/a7_angular/php/addLog.php';
  private deleteLogURL = 'http://localhost/a7_angular/php/deleteLog.php';
  private getFilteredLogsURL = 'http://localhost/a7_angular/php/getLogsByTypeAndSeverity.php';
  httpOptions = {
    headers: new HttpHeaders({
      'Content-Type': 'application/json'
    })
  };
  constructor(private http: HttpClient) { }

  public getAllLogs(): Observable<Log[]> {
    return this.http.get<Log[]>(this.getAllLogsURL);
  }

  public getAllLogsForUser(): Observable<Log[]> {
    return this.http.get<Log[]>(this.getAllLogsUserURL + `?user=${localStorage.getItem('username')}`);
  }

  public getLogsPaginated(pageSize: number, page: number): Observable<Log[]> {
    return this.http.get<Log[]>(this.getLogsPaginatedURL +
      `?pageSize=${pageSize}&page=${page}`);
  }

  public getLogsPaginatedForUser(pageSize: number, page: number): Observable<Log[]> {
    return this.http.get<Log[]>(this.getLogsPaginatedForUserURL +
      `?pageSize=${pageSize}&page=${page}` + `&user=${localStorage.getItem('username')}`);
  }

  public filterLogs(type: string, severity: string): Observable<Log[]> {
    return this.http.get<Log[]>(this.getFilteredLogsURL + `?type=${type}` + `&severity=${severity}`);
  }

  public addLog(type: string, severity: string, date: string, message: string): Observable<string> {
    return this.http.get(this.addLogURL + `?type=${type}` + `&severity=${severity}` +
      `&date=${date}` + `&user=${localStorage.getItem('username')}` + `&message=${message}`,
      {responseType: 'text'})
      .pipe(catchError(this.handleError<string>('addLog', '')));
  }

  public deleteLog(logId: number): Observable<string> {
    return this.http.get(this.deleteLogURL + `?logId=${logId}` + `&user=${localStorage.getItem('username')}`,
      {responseType: 'text'})
      .pipe(catchError(this.handleError<string>('deleteLog', '')));
  }
  
  private handleError<T>(operation = 'operation', result?: T) {
    return (error: any): Observable<T> => {
      console.error(error);
      return of(result as T);
    };
  }
}
